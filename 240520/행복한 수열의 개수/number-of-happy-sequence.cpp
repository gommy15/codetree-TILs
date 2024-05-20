#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100

int n, m, ans;
int grid[MAX_N][MAX_N];

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

bool CheckHappyRow(int row, int col) {
    for(int i=1; i<m; i++) {
        if(grid[row][col] != grid[row][col+i])
            return false;
    }

    return true;
}

bool CheckHappyCol(int row, int col) {
    for(int i=1; i<m; i++) {
        if(grid[row][col] != grid[row+i][col])
            return false;
    }

    return true;
}

void Simulate() {
    // 행 확인
    for(int row=0; row<n; row++) {
        for(int col=0; col<n; col++) {
            if(grid[row][col] != grid[row][col+1]) continue;

            if(InRange(row, col+m-1) && CheckHappyRow(row, col)) {
                ans++;
                break;
            }
        }
    }

    // 열 확인
    for(int col=0; col<n; col++) {
        for(int row=0; row<n; row++) {
            if(grid[row][col] != grid[row+1][col]) continue;

            if(InRange(row+m-1, col) && CheckHappyCol(row, col)) {
                ans++;
                break;
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;

    if(m == 1) {
        cout << 2*n;
        return 0;
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    Simulate();

    cout << ans;
    return 0;
}