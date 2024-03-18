#include <iostream>
using namespace std;
#define MAX_NM 100
#define WIND_RIGHT 1
#define WIND_LEFT 0

int n, m, q, r;
char d;

int grid[MAX_NM][MAX_NM];

void WindBlow(int row, int dir) {
    if(dir == WIND_LEFT) {
        int tmp = grid[row][m-1];
        for(int i=m-1; i>0; i--) {
            grid[row][i] = grid[row][i-1];
        }
        grid[row][0] = tmp;
    } else {
        int tmp = grid[row][0];
        for(int i=0; i<m-1; i++) {
            grid[row][i] = grid[row][i+1];
        }
        grid[row][m-1] = tmp;
    }
}

bool CheckEffect(int row1, int row2) {
    for(int i=0; i<m; i++) {
        if(grid[row1][i] == grid[row2][i])
            return true;
    }

    return false;
}

int ChangeWindDir(int dir) {
    return (dir == WIND_LEFT) ? WIND_RIGHT : WIND_LEFT;
}

void CheckGrid() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << grid[i][j] << ' ';
        }

        cout << '\n';
    }
    cout << '\n';
}

void Simulate(int start_row, int start_dir) {
    // 1. 주어진 행 바람 불기
    WindBlow(start_row, start_dir);

    // CheckGrid();

    // 방향 전환
    // cout << start_dir << '\n';
    start_dir = ChangeWindDir(start_dir);
    // cout << start_dir << '\n';

    //2. 위 방향으로 전파
    for(int row=start_row, dir=start_dir; row > 0; row--) {
        if(CheckEffect(row, row-1)) {
            WindBlow(row-1, dir);
            dir = ChangeWindDir(dir);
        } else 
            break;
        
        // CheckGrid();
    }

    // 3. 아래 방향으로 전파
    for(int row=start_row, dir=start_dir; row < (n-1); row++) {
        if(CheckEffect(row, row+1)) {
            WindBlow(row+1, dir);
            dir = ChangeWindDir(dir);
        } else 
            break;

        // CheckGrid();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m>>q;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i=0; i<q; i++) {
        cin >>r>>d;
        int start_dir = ((d == 'L') ? WIND_LEFT : WIND_RIGHT);

        Simulate(r-1, start_dir);
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << grid[i][j] << ' ';
        }

        cout << '\n';
    }
    return 0;
}