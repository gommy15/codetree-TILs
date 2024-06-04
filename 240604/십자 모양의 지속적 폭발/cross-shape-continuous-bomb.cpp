#include <iostream>
using namespace std;
#define MAX_N 200
#define DIR_NUM 4

int n, m;
int grid[MAX_N][MAX_N];

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

void Bomb(int x, int y, int t) {
    int dx[DIR_NUM] = {-1, 0, 1, 0};
    int dy[DIR_NUM] = {0, -1, 0, 1};

    for(int k=0; k<t; k++) {
        for(int d=0; d<DIR_NUM; d++) {
            int nx = x+dx[d]*k, ny = y+dy[d]*k;

            if(!InRange(nx, ny) || grid[nx][ny] == 0) continue;

            grid[nx][ny] = 0;
        }
    }
}

void Drop() {
    int next_grid[MAX_N][MAX_N] = {};

    for(int col = 0; col<n; col++) {
        int cnt = n-1;
        for(int row = n-1; row>=0; row--) {
            if(grid[row][col] != 0) {
                next_grid[cnt--][col] = grid[row][col];
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            grid[i][j] = next_grid[i][j];
        }
    }
}

void Simulate(int target_col) {
    for(int row=0; row<n; row++) {
        if(grid[row][target_col] != 0) {
            Bomb(row, target_col, grid[row][target_col]);
            Drop();
            break;
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    while(m--) {
        int c;
        cin >> c;
        Simulate(c-1);
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << grid[i][j] << ' ';
        }

        cout << '\n';
    }
    return 0;
}