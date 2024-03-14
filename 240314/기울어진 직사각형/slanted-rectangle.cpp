#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 20
#define DIR_NUM 4

int n;
int arr[MAX_N][MAX_N];
int dx[DIR_NUM] = {-1, -1, 1, 1}, dy[DIR_NUM] = {1, -1, -1, 1};

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

int GetScore(int x, int y, int k, int l) {
    int move_num[DIR_NUM] = {k, l, k, l};

    int sum_of_nums = 0;

    for(int d = 0; d<DIR_NUM; d++) {
        for(int q = 0; q<move_num[d]; q++) {
            x += dx[d];
            y += dy[d];

            if(!InRange(x, y)) return 0;

            sum_of_nums += arr[x][y];
        }
    }

    return sum_of_nums;
}

int main() {
    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    int ans = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=1; k<n; k++) {
                for(int l=1; l<n; l++) {
                    ans = max(ans, GetScore(i, j, k, l));
                }
            }
        }
    }

    cout << ans;
    return 0;
}

// 스스로 문제 푼 것의 문제점
// 한 방향의 변만 커지고 동시에 같은 크기로 커지는 것만 생각했을 뿐 동시에 다른 크기로 커지는 것을 고려하지 못함
// InRange로 검사하고 함수를 사용하여 계산하기 때문에 각각의 케이스를 나눌 필요가 없었음


// // 1과 3이 커질때
// int RecSumFist(int x, int y, int k) {
//     int sum = 0;
//     for(int i=0; i<4; i++) {
//         int dir_num = i;
//         if(dir_num%2 == 0) {
//             for(int j=0; j<k; j++) {
//                 int nx = x+dx[dir_num], ny=y+dy[dir_num];

//                 if(!InRange(nx, ny)) return 0;
//                 sum += arr[nx][ny];
//                 x = nx;
//                 y = ny;
//             }
//         } else {
//             int nx = x+dx[dir_num], ny=y+dy[dir_num];

//             if(!InRange(nx, ny)) return 0;
//             sum += arr[nx][ny];
//             x = nx;
//             y = ny;
//         }
//     }

//     return sum;
// }

// // 2과 4가 커질때
// int RecSumSecon(int x, int y, int k) {
//     int sum = 0;
//     for(int i=0; i<4; i++) {
//         int dir_num = i;
//         if(dir_num%2 == 1) {
//             for(int j=0; j<k; j++) {
//                 int nx = x+dx[dir_num], ny=y+dy[dir_num];

//                 if(!InRange(nx, ny)) return 0;
//                 sum += arr[nx][ny];
//                 x = nx;
//                 y = ny;
//             }
//         } else {
//             int nx = x+dx[dir_num], ny=y+dy[dir_num];

//             if(!InRange(nx, ny)) return 0;
//             sum += arr[nx][ny];
//             x = nx;
//             y = ny;
//         }
//     }

//     return sum;
// }

// // 1, 2, 3, 4가 동시에 커질 때
// int RecSumThird(int x, int y, int k) {
//     int sum = 0;
//     for(int i=0; i<4; i++) {
//         int dir_num = i;
//         for(int j=0; j<k; j++) {
//             // if(k == 2) {
//             //     cout << arr[x][y] << ' ';
//             // }
//             int nx = x+dx[dir_num], ny=y+dy[dir_num];

//             if(!InRange(nx, ny)) return 0;
//             sum += arr[nx][ny];
//             x = nx;
//             y = ny;
//         }
//     }

//     // cout << sum << '\n';
//     return sum;
// }

// int main() {
//     // 여기에 코드를 작성해주세요.
//     cin >> n;
//     for(int i=0; i<n; i++) {
//         for(int j=0; j<n; j++) {
//             cin >> arr[i][j];
//         }
//     }

//     int max_sum = 0;
//     for(int i=n-1; i>1; i--) {
//         for(int j=1; j<n-1; j++) {
//             int k = 1;
//             while(k < n) {
//                 max_sum = max(max_sum, RecSumFist(i, j, k));
//                 // cout << k << ' ' << max_sum << ' ';
//                 max_sum = max(max_sum, RecSumSecon(i, j, k));
//                 // cout << max_sum << ' ';
//                 max_sum = max(max_sum, RecSumThird(i, j, k));
//                 // cout << max_sum << '\n';
//                 k++;
//             }
//         }
//     }

//     cout << max_sum;

//     return 0;
// }