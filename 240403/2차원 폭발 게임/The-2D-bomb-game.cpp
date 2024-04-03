#include <iostream>
using namespace std;

#define MAX_N 100
#define BLANK -1
#define WILL_EXPLODE 0

int n, m, k, end_of_nums_1d, end_of_temp_1d;
int numbers_2d[MAX_N][MAX_N];
int numbers_1d[MAX_N];
int tmp_2d[MAX_N][MAX_N];
int tmp_1d[MAX_N];

int GetEndIdxOfExplosion(int start_idx, int curr_num) {
    int end_idx = start_idx+1;
    while(end_idx < end_of_nums_1d) {
        if(numbers_1d[end_idx] == curr_num) end_idx++;
        else
            break;
    }

    return end_idx-1;
}

void FillZero(int start_idx, int end_idx) {
    for(int i=start_idx; i<=end_idx; i++) {
        numbers_1d[i] = WILL_EXPLODE;
    }
}

void MoveToTemp() {
    end_of_temp_1d = 0;
    for(int i=0; i<end_of_nums_1d; i++) {
        if(numbers_1d[i] != WILL_EXPLODE)
            tmp_1d[end_of_temp_1d++] = numbers_1d[i];
    }
}

void CopyFromTemp() {
    end_of_nums_1d = end_of_temp_1d;
    for(int i=0; i<end_of_nums_1d; i++) {
        numbers_1d[i] = tmp_1d[i];
    }
}

void Explode() {
    bool did_explode;
    do {
        did_explode = false;
        for(int curr_idx = 0; curr_idx<end_of_nums_1d; curr_idx++) {
            if(numbers_1d[curr_idx] == WILL_EXPLODE) {
                continue;
            }

            int end_idx = GetEndIdxOfExplosion(curr_idx, numbers_1d[curr_idx]);

            if(end_idx - curr_idx + 1 >= m) {
                FillZero(curr_idx, end_idx);
                did_explode = true;
            }
        }

        MoveToTemp();
        CopyFromTemp();
    } while(did_explode);
}

void CopyColumn(int col) {
    end_of_nums_1d = 0;
    for(int i=0; i<n; i++) {
        if(numbers_2d[i][col] != BLANK)
            numbers_1d[end_of_nums_1d++] = numbers_2d[i][col];
    }
}

void CopyResult(int col) {
    int result_idx = end_of_nums_1d-1;
    for(int i=n-1; i>=0; i--) {
        if(result_idx >= 0)
            numbers_2d[i][col] = numbers_1d[result_idx--];
        else
            numbers_2d[i][col] = BLANK;
    }
}


void Simulate() {
    for(int col=0; col<n; col++) {
        CopyColumn(col);
        Explode();
        CopyResult(col);
    }
}

void Rotate() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            tmp_2d[i][j] = BLANK;
        }
    }

    int curr_idx;
    for(int i=n-1; i>=0; i--) {
        curr_idx = n-1;
        for(int j=n-1; j>=0; j--) {
            if(numbers_2d[i][j] != BLANK)
                tmp_2d[curr_idx--][n-i-1] = numbers_2d[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            numbers_2d[i][j] = tmp_2d[i][j];
        }
    }
}

int main() {
    cin >>n>>m>>k;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> numbers_2d[i][j];
        }
    }

    Simulate();
    for(int i=0; i<k; i++) {
        Rotate();
        Simulate();
    }

    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(numbers_2d[i][j] != BLANK) ans++;
        }
    }

    cout << ans;
}


// 보류
// #include <iostream>
// using namespace std;
// #define MAX_N 100

// int n, m, k;
// int grid[MAX_N][MAX_N], next_grid[MAX_N][MAX_N];

// void Bumb() {
    
//     for(int col=0; col<n; col++) {
//         int st = 0;
//         int cnt = 1;
//         for(int row=1; row<n; row++) {
//             if(grid[st][col] != grid[row][col]) {
//                 if(cnt >= m) {
//                     for(int i=st; i<st+cnt; i++) {
//                         grid[i][col] = 0;
//                     }
//                 }
//                 cnt = 1;
//                 st = row;
//             } else
//                 cnt++;
//         }

//         if(cnt >= m) {
//             for(int i=st; i<st+cnt; i++) {
//                 grid[i][col] = 0;
//             }
//         }
//     }
// }

// void Gravity() {
//     for(int i=0; i<n; i++) {
//         for(int j=0; j<n; j++) {
//             next_grid[i][j] = 0;
//         }
//     }

//     for(int j=0; j<n; j++) {
//         int cnt = n-1;
//         for(int i=n-1; i>=0; i--) {
//             if(grid[i][j] != 0) {
//                 next_grid[cnt--][j] = grid[i][j];
//             }
//         }
//     }

//     for(int i=0; i<n; i++) {
//         for(int j=0; j<n; j++) {
//             grid[i][j] = next_grid[i][j];
//         }
//     }
// }

// void Rotate() {
//     for(int i=0; i<n; i++) {
//         for(int j=0; j<n; j++) {
//             next_grid[i][j] = 0;
//         }
//     }

//     for(int i=0; i<n; i++) {
//         for(int j=0; j<n; j++) {
//             next_grid[i][j] = grid[n-j-1][i];
//         }
//     }

//     for(int i=0; i<n; i++) {
//         for(int j=0; j<n; j++) {
//             grid[i][j] = next_grid[i][j];
//         }
//     }
// }

// void Simulate() {
//     Bumb();

//     // cout << "\n***B.   " << '\n';
//     // for(int i=0; i<n; i++) {
//     //     for(int j=0; j<n; j++) {
//     //         cout << grid[i][j] << ' ';
//     //     }
//     //     cout << '\n';
//     // }

//     Gravity();

//     // cout << "\n***G.   " << '\n';
//     // for(int i=0; i<n; i++) {
//     //     for(int j=0; j<n; j++) {
//     //         cout << grid[i][j] << ' ';
//     //     }
//     //     cout << '\n';
//     // }

//     Rotate();

//     // cout << "\n***R.   " << '\n';
//     // for(int i=0; i<n; i++) {
//     //     for(int j=0; j<n; j++) {
//     //         cout << grid[i][j] << ' ';
//     //     }
//     //     cout << '\n';
//     // }

//     Gravity();

//     cout << "\n***G.   " << '\n';
//     for(int i=0; i<n; i++) {
//         for(int j=0; j<n; j++) {
//             cout << grid[i][j] << ' ';
//         }
//         cout << '\n';
//     }
// }

// int main() {
//     // 여기에 코드를 작성해주세요.
//     cin >>n>>m>>k;

//     for(int i=0; i<n; i++) {
//         for(int j=0; j<n; j++) {
//             cin >> grid[i][j];
//         }
//     }

//     for(int i=0; i<k; i++) {
//         // cout << i+1;
//         Simulate();
//     }

//     Bumb();

//     int ans = 0;
//     for(int i=0; i<n; i++) {
//         for(int j=0; j<n; j++) {
//             if(grid[i][j] != 0) ans++;
//         }
//     }

//     cout << ans;
//     return 0;
// }