// #include <iostream>
// using namespace std;
// #define MAX_N 100

// int n, m, k;
// int grid[MAX_N][MAX_N];

// bool AllBlank(int row, int col_st, int col_ed) {
//     for(int col = col_st; col <= col_ed; col++) {
//         if(grid[row][col] == 1)
//             return false;
//     }

//     return true;
// }

// int GetTargetRow() {
//     for(int row=0; row<n-1; row++) {
//         if(!AllBlank(row+1, k, k+m-1))
//             return row;
//     }

//     return n-1;
// }

// int main() {
//     cin >>n>>m>>k;
//     k--;

//     for(int i=0; i<n; i++) {
//         for(int j=0; j<n; j++) {
//             cin >> grid[i][j];
//         }
//     }

//     int target_row = GetTargetRow();

//     for(int col = k; col<k+m; col++) {
//         grid[target_row][col] = 1;
//     }

//     for(int i=0; i<n; i++) {
//         for(int j=0; j<n; j++) {
//             cout << grid[i][j] << ' ';
//         }

//         cout << '\n';
//     }
// }


//틀린 테스트케이스 찾을 때까지 보류
// 틀린 이유 -> 아래에서부터 블록이 쌓여있다고 전제했기 때문에 위에서 내려와도 아래가 비어있으면 아래에 채워짐 -> 그럴 일은 일어나지 않음

#include <iostream>
using namespace std;
#define MAX_N 100

int n, m, k;
int grid[MAX_N+1][MAX_N+1];

void Simulate() {
    int target_row = n;
    for(int row = 1; row <= n; row++) {
        bool possible = true;
        for(int col = k; col < k+m; col++) {
            if(grid[row][col] == 1) {
                possible = false;
                target_row = row-1;
                break;
            }
        }

        if(!possible) {
            break;
        }
    }

    for(int col = k; col < k+m; col++) {
        grid[target_row][col] = 1;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m>>k;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> grid[i][j];
        }
    }

    Simulate();

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}