// Memoization 방식
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

#define MAX_N 500
#define DIR_NUM 4

int n;
int grid[MAX_N][MAX_N], dp[MAX_N][MAX_N];

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

int FindMax(int x, int y) {
    if(dp[x][y] != -1)
        return dp[x][y];
    
    int best = 1;

    int dx[DIR_NUM] = {-1, 1, 0, 0};
    int dy[DIR_NUM] = {0, 0, -1, 1};

    for(int d=0; d<DIR_NUM; d++) {
        int nx = x+dx[d], ny = y+dy[d];
        if(InRange(nx, ny) && grid[nx][ny] > grid[x][y]) {
            best = max(best, FindMax(nx, ny)+1);
        }
    }

    return dp[x][y] = best;
}

int main() {
    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
            dp[i][j] = -1;
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            ans = max(ans, FindMax(i, j));
        }
    }

    cout << ans;
}



// // tabulation 방식
// #include <iostream>
// #include <algorithm>
// #include <tuple>
// #include <vector>
// using namespace std;
// #define MAX_N 500
// #define DIR_NUM 4

// int n;
// int grid[MAX_N][MAX_N], dp[MAX_N][MAX_N];
// vector<tuple<int, int, int>> cells;
// int ans;

// bool InRange(int x, int y) {
//     return 0<=x && x<n && 0<=y && y<n;
// }

// int main() {
//     // 여기에 코드를 작성해주세요.
//     cin >> n;

//     for(int i=0; i<n; i++) {
//         for(int j=0; j<n; j++) {
//             cin >> grid[i][j];
//             cells.push_back(make_tuple(grid[i][j], i, j));

//             //초기화 (해당 칸에서 시작하는 경우)
//             dp[i][j] = 1;
//         }
//     }

//     sort(cells.begin(), cells.end());

//     int dx[DIR_NUM] = {-1, 1, 0, 0};
//     int dy[DIR_NUM] = {0, 0, -1, 1};

//     for(int i=0; i<cells.size(); i++) {
//         int x, y;
//         tie(ignore, x, y) = cells[i];

//         for(int d=0; d<DIR_NUM; d++) {
//             int nx = x+dx[d], ny = y+dy[d];
//             if(InRange(nx, ny) && grid[nx][ny] > grid[x][y])
//                 dp[nx][ny] = max(dp[nx][ny], dp[x][y]+1);
//         }
//     }

//     for(int i=0; i<n; i++) {
//         for(int j=0; j<n; j++) {
//             ans = max(ans, dp[i][j]);
//         }
//     }

//     cout << ans;
//     return 0;
// }