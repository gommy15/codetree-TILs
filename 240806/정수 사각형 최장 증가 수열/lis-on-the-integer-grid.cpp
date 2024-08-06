#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#define MAX_N 500
#define DIR_NUM 4

int n;
int dp[MAX_N][MAX_N], nums[MAX_N][MAX_N];

vector<tuple<int, int, int>> spots;
int ans;

int dx[DIR_NUM] = {-1, 1, 0, 0}, dy[DIR_NUM] = {0, 0, -1, 1};

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

void DpInit() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            dp[i][j] = 1;
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> nums[i][j];

            spots.push_back(make_tuple(nums[i][j], i, j));
        }
    }

    sort(spots.begin(), spots.end());
    DpInit();

    for(int v=0; v<(int)spots.size(); v++) {
        int x, y;
        tie(ignore, x, y) = spots[v];

        for(int d=0; d<DIR_NUM; d++) {
            int nx = x+dx[d], ny = y+dy[d];

            if(!InRange(nx, ny)) continue;

            if(nums[x][y] < nums[nx][ny]) {
                dp[nx][ny] = max(dp[x][y]+1, dp[nx][ny]);
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans;
    
    return 0;
}