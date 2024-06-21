#include <iostream>
#include <cmath>
using namespace std;
#define MAX_N 100
#define DIR_NUM 4

int n, m;
bool grid[MAX_N][MAX_N], next_grid[MAX_N][MAX_N];

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

void MakeBumb(int x, int y, int t) {
    int dx[DIR_NUM] = {0, -1, 0, 1}, dy[DIR_NUM] = {1, 0, -1, 0};

    for(int d=0; d<DIR_NUM; d++) {
        int nx = x+dx[d]*t, ny = y+dy[d]*t;

        if(!InRange(nx, ny)) continue;
        if(!grid[nx][ny]) next_grid[nx][ny] = 1;
    }
}

void Simulate(int t) {
    int dis = pow(2, t-1);

    // cout << dis << "  ********************\n";

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(grid[i][j]) {
                MakeBumb(i, j, dis);
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(next_grid[i][j])
                grid[i][j] = 1;

            // cout << next_grid[i][j] << ' ';
        }
        // cout << '\n';
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    int r, c;
    cin >> n>>m>>r>>c;


    grid[r-1][c-1] = 1;
    next_grid[r-1][c-1] = 1;

    int t = 1;

    while(true) {
        if(t > m) break;
        Simulate(t);
        t++;
    }

    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(grid[i][j]) ans++;
        }
    }

    cout << ans;
    return 0;
}