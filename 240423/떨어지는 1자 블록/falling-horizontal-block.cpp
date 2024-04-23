#include <iostream>
using namespace std;
#define MAX_N 100

int n, m, k;
int grid[MAX_N][MAX_N];

void Simulate(int col) {
    int row = 0;
    bool possible = true;

    while(true) {
        for(int i=0; i<m; i++) {
            if(grid[row][col+i] == 1) {
                possible = false;
                break;
            }
        }

        if(possible) row++;
        else {
            row--;
            for(int i=0; i<m; i++) {
                grid[row][col+i] = 1;
            }
            return;
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m>>k;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    Simulate(k-1);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}