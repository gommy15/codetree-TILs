#include <iostream>
using namespace std;
#define MAX_N 20
#define DIR_NUM 4

int n, m, t, r, c;
int grid[MAX_N+1][MAX_N+1];
int grid_ball[MAX_N+1][MAX_N+1];
int dx[DIR_NUM] = {-1, 1, 0, 0}, dy[DIR_NUM] = {0, 0, -1, 1};

bool InRange(int x, int y) {
    return 0<x && x<=n && 0<y && y<=n;
}

void RemoveBall() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(grid_ball[i][j] >= 2)
                grid_ball[i][j] = 0;
        }
    }
}

void Simulate() {
    int tmp[MAX_N+1][MAX_N+1] = {};
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(grid_ball[i][j] == 1) {
                int max_num = 0;
                int next_x, next_y;
                for(int k=0; k<DIR_NUM; k++) {
                    int nx = i+dx[k], ny = j+dy[k];
                    // if(!InRange(nx, ny)) continue;

                    if(InRange(nx, ny) && max_num < grid[nx][ny]) {
                        next_x = nx;
                        next_y = ny;
                        max_num = grid[nx][ny];
                    }
                }
                if(max_num == grid[i][j]) tmp[i][j]++;
                else tmp[next_x][next_y]++;
            }
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            grid_ball[i][j] = tmp[i][j];
            // cout << tmp[i][j] << ' ';
        }

        // cout << '\n';
    }
    // cout << '\n';

    RemoveBall();
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m>>t;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i=0; i<m; i++) {
        cin >> r>>c;
        grid_ball[r][c]++;
    }

    while(t--) {
        Simulate();
    }

    int ans = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            ans += grid_ball[i][j];
        }
    }

    cout << ans;
    return 0;
}