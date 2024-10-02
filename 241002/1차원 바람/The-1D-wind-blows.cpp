#include <iostream>
using namespace std;
#define MAX_NM 100
#define SHIFT_LEFT 1
#define SHIFT_RIGHT 0

int n, m, q;
int a[MAX_NM+1][MAX_NM+1];

void Shift(int r, int d) {
    if(d == SHIFT_RIGHT) {
        int tmp = a[r][m];
        for(int col = m; col>=2; col--) {
            a[r][col] = a[r][col-1];
        }
        a[r][1] = tmp;
    } else {
        int tmp = a[r][1];
        for(int col=1; col<m; col++) {
            a[r][col] = a[r][col+1];
        }
        a[r][m] = tmp;
    }
}

bool Flip(int dir) {
    return(dir == SHIFT_LEFT) ? SHIFT_RIGHT:SHIFT_LEFT;
}

bool HasSameNumber(int r1, int r2) {
    for(int col=1; col<=m; col++) {
        if(a[r1][col] == a[r2][col])
            return true;
    }

    return false;
}

void Simulate(int r, int d) {
    Shift(r, d);

    d = Flip(d);

    for(int row = r, dir = d; row>1; row--) {
        if(HasSameNumber(row, row-1)) {
            Shift(row-1, dir);
            dir = Flip(dir);
        }
        else break;
    }

    for(int row = r, dir = d; row<n; row++) {
        if(HasSameNumber(row, row+1)) {
            Shift(row+1, dir);
            dir = Flip(dir);
        }
        else break;
    }
}

int main() {
    cin >> n>>m>>q;

    for(int row=1; row<=n; row++) {
        for(int col=1; col<=m; col++) {
            cin >> a[row][col];
        }
    }

    while(q--) {
        int r; char d;
        cin >> r>>d;

        Simulate(r, d=='L'? SHIFT_RIGHT:SHIFT_LEFT);
    }

    for(int row=1; row<=n; row++) {
        for(int col=1; col<=m; col++) {
            cout << a[row][col] << ' ';
        }
        cout << '\n';
    }
}





// #include <iostream>
// using namespace std;
// #define MAX_NM 100
// #define NUM_Q 100

// int n, m, q;
// int grid[MAX_NM][MAX_NM];

// void MoveL(int r) {
//     int tmp = grid[r][0];

//     for(int i=0; i<m-1; i++) {
//         grid[r][i] = grid[r][i+1];
//     }

//     grid[r][m-1] = tmp;
// }

// void MoveR(int r) {
//     int tmp = grid[r][m-1];

//     for(int j=m-1; j>0; j--) {
//         grid[r][j] = grid[r][j-1];
//     }

//     grid[r][0] = tmp;
// }

// bool HasSameNumber(int r1, int r2) {
//     for(int j=0; j<m; j++) {
//         if(grid[r1][j] == grid[r2][j])
//             return true;
//     }

//     return false;
// }

// void Swipe(int r, char d) {
//     if(d == 'L') {
//         MoveL(r);
//         d = 'R';
//     }
//     else {
//         MoveR(r);
//         d == 'L';
//     }

//     for(int row = r, dir = d; row > 0; row--) {
//         if(HasSameNumber(row, row-1)) {
//             if(dir == 'L') {
//                 MoveL(row-1);
//                 dir = 'R';
//             } else {
//                 MoveR(row-1);
//                 dir = 'L';
//             }
//         } else 
//             break;
//     }

//     for(int row = r, dir = d; row < n-1; row++) {
//         if(HasSameNumber(row, row+1)) {
//             if(dir == 'L') {
//                 MoveL(row-1);
//                 dir = 'R';
//             } else {
//                 MoveR(row-1);
//                 dir = 'L';
//             }
//         } else 
//             break;
//     }

//     // for(int j=0; j<m; j++) {
//     //     if(r>0 && grid[r][j] == grid[r-1][j]) {
//     //         Swipe(r-1, d);
//     //         break;
//     //     } else if (r <n && grid[r][j] == grid[r+1][j]) {
//     //         Swipe(r+1, d);
//     //     }
//     // }
// }

// int main() {
//     // 여기에 코드를 작성해주세요.
//     cin >> n>>m>>q;
//     for(int i=0; i<n; i++) {
//         for(int j=0; j<m; j++) {
//             cin >> grid[i][j]; 
//         }
//     }

//     for(int i=0; i<q; i++) {
//         int r; char d;
//         cin >> r>>d;

//         Swipe(r-1, d);
//     }

//     for(int i=0; i<n; i++) {
//         for(int j=0; j<m; j++) {
//             cout << grid[i][j] << ' ';
//         }
//         cout << '\n';
//     }

//     return 0;
// }