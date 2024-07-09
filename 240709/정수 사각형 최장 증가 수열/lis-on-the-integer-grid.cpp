#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#define MAX_N 500
#define DIR_NUM 4

int n;
int num[MAX_N][MAX_N], dp[MAX_N][MAX_N];

vector<tuple<int, int, int>> spots;
int ans;

int dx[DIR_NUM] = {-1, 1, 0, 0};
int dy[DIR_NUM] = {0, 0, -1, 1};

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> num[i][j];

            spots.push_back(make_tuple(num[i][j], i, j));
        }
    }

    sort(spots.begin(), spots.end());

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            dp[i][j] = 1;
        }
    }

    for(int i=0; i<spots.size(); i++) {
        int x, y;
        tie(ignore, x, y) = spots[i];

        for(int d=0; d<DIR_NUM; d++) {
            int nx = x+dx[d], ny = y+dy[d];
            if(!InRange(nx, ny)) continue;

            if(num[nx][ny] > num[x][y]) {
                dp[nx][ny] = max(dp[nx][ny], dp[x][y]+1);
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