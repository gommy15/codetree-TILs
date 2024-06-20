#include <iostream>
using namespace std;
#define MAX_N 100

int n, m, k;
bool grid[MAX_N][MAX_N];

int FindRow() {
    for(int r=0; r<n; r++) {
        for(int c=k; c<k+m; c++) {
            if(grid[r][c] == 1)
                return r-1;
        }
    }
    return n-1;
}

void Simulate() {
    int in_row = FindRow();

    for(int i=k; i<k+m; i++) {
        grid[in_row][i] = 1;
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

    k--;

    Simulate();

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}