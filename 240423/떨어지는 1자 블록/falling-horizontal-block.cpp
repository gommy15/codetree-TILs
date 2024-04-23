#include <iostream>
using namespace std;
#define MAX_N 100

int n, m, k;
int grid[MAX_N][MAX_N];

bool AllBlank(int row, int col_s, int col_e) {
    for(int col=col_s; col<=col_e; col++) {
        if(grid[row][col]) return false;
    }

    return true;
}

int GetTargetRow() {
    for(int row=0; row<n-1; row++) {
        if(!AllBlank(row+1, k, k+m-1))
            return row;
    }

    return n-1;
}

int main() {
    cin >>n>>m>>k;
    k--;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    int target_row = GetTargetRow();

    for(int col=k; col<k+m; col++) {
        grid[target_row][col] = 1;
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}


// #include <iostream>
// using namespace std;
// #define MAX_N 100

// int n, m, k;
// int grid[MAX_N][MAX_N];

// void Simulate(int col) {
//     int row = 0;
//     bool possible = true;

//     while(true) {
//         if(row >= n) {
//             row--;
//             for(int i=0; i<m; i++) {
//                 grid[row][col+i] = 1;
//             }
//             return;
//         }
//         for(int i=0; i<m; i++) {
//             if(grid[row][col+i] == 1) {
//                 possible = false;
//                 break;
//             }
//         }

//         if(possible) row++;
//         else {
//             row--;
//             for(int i=0; i<m; i++) {
//                 grid[row][col+i] = 1;
//             }
//             return;
//         }
//     }
// }

// int main() {
//     // 여기에 코드를 작성해주세요.
//     cin >> n>>m>>k;

//     for(int i=0; i<n; i++) {
//         for(int j=0; j<n; j++) {
//             cin >> grid[i][j];
//         }
//     }

//     Simulate(k-1);

//     for(int i=0; i<n; i++) {
//         for(int j=0; j<n; j++) {
//             cout << grid[i][j] << ' ';
//         }
//         cout << '\n';
//     }
//     return 0;
// }