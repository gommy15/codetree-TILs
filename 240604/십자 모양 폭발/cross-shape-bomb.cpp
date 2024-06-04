#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 200
#define DIR_NUM 4

int n;
int grid[MAX_N][MAX_N], tmp[MAX_N][MAX_N];


bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

void Bomb(int x, int y, int t) {
    int dx[DIR_NUM] = {-1, 0, 1, 0};
    int dy[DIR_NUM] = {0, 1, 0, -1};

    for(int i=0; i<t; i++) {
        if(i >= n) break;

        for(int d=0; d<DIR_NUM; d++) {
            int nx = x+dx[d]*i, ny=y+dy[d]*i;

            if(!InRange(nx, ny) || grid[nx][ny] == 0) continue;

            grid[nx][ny] = 0;
        }
    }
}

void Move() {
    for(int col=0; col<n; col++) {
        int cnt = n-1;
        for(int row=n-1; row>=0; row--) {
            if(grid[row][col] != 0) {
                tmp[cnt--][col] = grid[row][col];
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            grid[i][j] = tmp[i][j];
        }
    }
}

void Simulate(int r, int c) {
    Bomb(r, c, grid[r][c]);

    Move();
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    int r, c;
    cin >> r>>c;
    Simulate(r-1, c-1);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << grid[i][j] << ' ';
        }

        cout << '\n';
    }
    return 0;
}