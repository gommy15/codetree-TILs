#include <iostream>
using namespace std;
#define MAX_N 100

int n, m, k;
int grid[MAX_N+1][MAX_N+1];

void Simulate() {
    k--;
    for(int row = n-1; row >=0; row--) {
        bool possible = true;
        for(int col = k; col < k+m; col++) {
            if(grid[row][col] == 1) {
                possible = false;
                break;
            }
        }

        if(possible) {
            for(int col = k; col < k+m; col++) {
                grid[row][col] = 1;
            }

            break;
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

    Simulate();

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}