// 마름모 내부인지 확인하는 공식을 아는 것이 중요!!!
// 마름모 중앙의 위치를 (a, b), 임의의 위치를 (c, d)라고 했을 때
// |c-a| + |d-b| <= k 이면 해당 위치는 마름모에 포함된다고 볼 수 있음!

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 20

int n, m;
int arr[MAX_N][MAX_N];

// 주어진 k에 대한 마름모 넓이 반환
int GetArea(int k) {
    return k*k + (k+1)*(k+1);
}

// 주어진 k에 대하여 채굴 가능한 금의 개수를 반환
int GetNumOfGold(int row, int col, int k) {
    int num_of_gold = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            // 모든 영역을 돌면서 주어진 마름모 안에 들어가는지 확인
            // row와 col을 마름모의 중앙 위치라고 가정
            if(abs(row-i)+abs(col-j) <= k) {
                num_of_gold += arr[i][j];
            }
        }
    }

    return num_of_gold;
}

int main() {
    cin >> n>>m;

    for(int row=0; row<n; row++) {
        for(int col=0; col<n; col++) {
            cin >> arr[row][col];
        }
    }

    int max_gold = 0;
    for(int row=0; row<n; row++) {
        for(int col=0; col<n; col++) {
            // 우측 하단이 마름모 중심일 때 모든 격자를 커버하려면 k가 2*(n-1)까지 커져야 함
            for(int k=0; k<= 2*(n-1); k++) {
                int num_of_gold = GetNumOfGold(row, col, k);

                if(num_of_gold*m >= GetArea(k)) {
                    max_gold = max(max_gold, num_of_gold);
                }
            }
        }
    }

    cout << max_gold;    
}



//이전 풀이
// int n, m;
// int arr[MAX_N][MAX_N];
// int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

// bool InRange(int x, int y) {
//     return 0<=x && x<n && 0<=y && y<n;
// }

// int main() {
//     // 여기에 코드를 작성해주세요.
//     cin >> n>>m;
//     for(int i=0; i<n; i++) {
//         for(int j=0; j<n; j++) {
//             cin >> arr[i][j];
//         }
//     }
//     int k = 0;
//     int ans = 0;
//     for(int i=0; i<n; i++) {
//         for(int j=0; j<n; j++) {
//             if(arr[i][j] == 1) {
//                 ans = 1;
//                 k++;
//                 break;
//             }
//         }
//         if(k > 0) break;
//     }

//     if(k == n) {
//         cout << ans;
//         return 0;
//     }


//     while(true) {
//         int max_cnt = 0;
//         for(int i=0; i<n; i++) {
//             for(int j=0; j<n; j++) {
//                 int cnt = 0;
//                 // 마름모 날개에 있는 금 개수 확인
//                 for(int l=0; l<4; l++) {
//                     int nx = i+dx[l]*k, ny = j+dy[l]*k;
//                     if(!InRange(nx, ny)) continue;

//                     if(arr[nx][ny] == 1) cnt++;
//                 }

//                 if(k > 1) {
//                     int nx = i-(k-1), ny = j-(k-1);
//                     for(int a=nx; a<=nx+k; a++) {
//                         for(int b=ny; b<=ny+k; b++) {
//                             if(!InRange(a, b)) continue;

//                             if(arr[a][b] == 1) cnt++;
//                         }
//                     }
//                 } else {
//                     if(arr[i][j] == 1) cnt++;
//                 }

//                 max_cnt = max(max_cnt, cnt);
//             }
//         }
//         // cout << max_cnt << ' ' << (k*k + (k+1)*(k+1)) << '\n';
//         if(max_cnt*m > (k*k + (k+1)*(k+1)))
//             ans = max(ans, max_cnt);
//         else
//             break;

//         k++;
//     }

//     cout << ans;
//     return 0;
// }