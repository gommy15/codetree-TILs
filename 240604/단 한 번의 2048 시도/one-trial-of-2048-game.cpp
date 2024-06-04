#include <iostream>
using namespace std;
#define GRID 4
#define ASCII 128

int grid[GRID][GRID], next_grid[GRID][GRID], mapper[ASCII];

void Rotate() {
    for(int i=0; i<GRID; i++) {
        for(int j=0; j<GRID; j++) {
            next_grid[i][j] = 0;
        }
    }

    for(int i=0; i<GRID; i++) {
        for(int j=0; j<GRID; j++) {
            next_grid[i][j] = grid[GRID-j-1][i];
        }
    }

    for(int i=0; i<GRID; i++) {
        for(int j=0; j<GRID; j++) {
            grid[i][j] = next_grid[i][j];
        }
    }
}

void Match() {
    for(int col=0; col<GRID; col++) {
        for(int row=GRID-1; row>=1; row--) {
            if(grid[row][col] != 0 && grid[row][col] == grid[row-1][col]) {
                grid[row][col] *= 2;
                grid[row-1][col] = 0;
            }
        }
    }
}

void Drop() {
    for(int i=0; i<GRID; i++) {
        for(int j=0; j<GRID; j++) {
            next_grid[i][j] = 0;
        }
    }

    for(int col=0; col<GRID; col++) {
        int cnt = GRID-1;
        for(int row=GRID-1; row>=0; row--) {
            if(grid[row][col] != 0)
                next_grid[cnt--][col] = grid[row][col];
        }
    }

    for(int i=0; i<GRID; i++) {
        for(int j=0; j<GRID; j++) {
            grid[i][j] = next_grid[i][j];
        }
    }
}

void Simulate(int move_dir) {
    for(int i=0; i<move_dir; i++) {
        Rotate();
    }

    Drop();
    Match();
    Drop();

    for(int i=0; i<4-move_dir; i++) {
        Rotate();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    for(int i=0; i<GRID; i++) {
        for(int j=0; j<GRID; j++) {
            cin >> grid[i][j];
        }
    }

    char dir;
    cin >> dir;
    mapper['D'] = 0;
    mapper['R'] = 1;
    mapper['U'] = 2;
    mapper['L'] = 3;

    Simulate(mapper[dir]);

    for(int i=0; i<GRID; i++) {
        for(int j=0; j<GRID; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}