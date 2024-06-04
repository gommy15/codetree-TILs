#include <iostream>
using namespace std;
#define MAX_N 100

int n, m, k;
int grid[MAX_N][MAX_N], next_grid[MAX_N][MAX_N];

int CntBumbs(int x, int y) {
    int cnt = 1;
    for(int i=x+1; i<n; i++) {
        if(grid[x][y] != grid[i][y]) break;

        cnt++;
    }

    return cnt;
}

void Bomb(int x, int y, int cnt) {
    for(int i=x; i<x+cnt; i++) {
        grid[i][y] = 0;
    }
}

void Drop() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            next_grid[i][j] = 0;
        }
    }

    for(int col=0; col<n; col++) {
        int cnt = n-1;
        for(int row=n-1; row>=0; row--) {
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

void Rotate() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            next_grid[i][j] = 0;
        }
    }

    for(int i=n-1; i>=0; i--) {
        for(int j=n-1;j>=0; j--) {
            next_grid[j][n-i-1] = grid[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            grid[i][j] = next_grid[i][j];
        }
    }
}

void Simulate() {
    for(int col=0; col<n; col++) {
        for(int row=0; row<n; row++) {
            if(grid[row][col] != 0) {
                int cnt = CntBumbs(row, col);
                if(cnt >= m) {
                    Bomb(row, col, cnt);
                }
            }
        }
    }

    Drop();

    Rotate();
    Drop();
}

bool LastBumb() {
    bool exist = false;
    for(int col=0; col<n; col++) {
        for(int row=0; row<n; row++) {
            if(grid[row][col] != 0) {
                int cnt = CntBumbs(row, col);
                if(cnt >= m) {
                    Bomb(row, col, cnt);
                    exist = true;
                }
            }
        }
    }

    if(!exist) return exist;

    Drop();
    return exist;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m>>k;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    while(k--) {
        Simulate();

        // cout << "*******************************\n";
        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<n; j++) {
        //         cout << grid[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }

    }

    while(LastBumb()) { }


    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(grid[i][j] != 0) ans++;
        }
    }

    cout << ans;
    return 0;
}