#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
#define MAX_N 100
#define DIR_NUM 4

int n, next_x, next_y;
int grid[MAX_N][MAX_N];

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

bool CanGo(int x, int y) {
    int dx[DIR_NUM] = {-1, 1, 0, 0};
    int dy[DIR_NUM] = {0, 0, -1, 1};

    for(int i=0; i<DIR_NUM; i++) {
        int nx = x+dx[i], ny = y+dy[i];

        if(!InRange(nx, ny)) continue;

        if(grid[x][y] < grid[nx][ny]) {
            next_x = nx;
            next_y = ny;
            // cout << "*****************************\n";
            // cout << grid[x][y] << grid[nx][ny] << '\n';
            // cout << next_x << ' ' << next_y << '\n';
            return true;
        }
    }

    return false;
}

void Simulate(int x, int y) {
    // int cur_x = x, cur_y = y;
    
    while(CanGo(x, y)) {
        // if(CanGo(cur_x, cur_y) == false) break;

        x = next_x;
        y = next_y;

        // cout << cur_x << ' ' << cur_y << '\n';
        cout << grid[x][y] << ' ';
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    int r, c;
    cin >> n >> r>>c;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    cout << grid[r-1][c-1] << ' ';
    Simulate(r-1, c-1);
    
    return 0;
}