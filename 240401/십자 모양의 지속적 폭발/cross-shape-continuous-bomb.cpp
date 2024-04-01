#include <iostream>
using namespace std;
#define MAX_N 100
#define DIR_NUM 4

int n, m;
int grid[MAX_N][MAX_N], next_grid[MAX_N][MAX_N];

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

void Bumb(int x, int y) {
    int dx[DIR_NUM] = {0, -1, 0, 1};
    int dy[DIR_NUM] = {1, 0, -1, 0};
    int area = grid[x][y]-1;

    grid[x][y] = 0;

    if(area == 0) {
        return;
    }

    for(int i=1; i<=area; i++) {
        for(int d=0; d<DIR_NUM; d++) {
            int nx = x+dx[d]*i, ny = y+dy[d]*i;

            if(!InRange(nx, ny)) break;
            grid[nx][ny] = 0;
        }
    }
}

void Gravity() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            next_grid[i][j] = 0;
    }

    for(int j=0; j<n; j++) {
        int cnt = n-1;
        for(int i=n-1; i>=0; i--) {
            if(grid[i][j] != 0) {
                next_grid[cnt--][j] = grid[i][j];
            }
        }

        // cout << "**** " << j << '\n';
        // for(int k=0; k<n; k++) {
        //     for(int l=0; l<n; l++) {
        //         cout << next_grid[k][l] << ' ';
        //     }
        //     cout << '\n';
        // }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            grid[i][j] = next_grid[i][j];
        }
    }
}

void Simulate(int col) {

    for(int row=0; row<n; row++) {
        if(grid[row][col] != 0) {
            Bumb(row, col);

            // for(int i=0; i<n; i++) {
            //     for(int j=0; j<n; j++) {
            //         cout << grid[i][j] << ' ';
            //     }
            //     cout << '\n';
            // }
            
            Gravity();

            // for(int i=0; i<n; i++) {
            //     for(int j=0; j<n; j++) {
            //         cout << grid[i][j] << ' ';
            //     }
            //     cout << '\n';
            // }
            break;
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i=0; i<m; i++) {
        int c;
        cin >> c;
        // cout <<"**** " << c << '\n';
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