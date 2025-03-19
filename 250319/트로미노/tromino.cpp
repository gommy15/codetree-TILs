#include <bits/stdc++.h>
using namespace std;

#define MAX_NM 200
#define DIR_NUM 4

int dx[DIR_NUM] = {-1, 0, 1, 0}, dy[DIR_NUM] = {0, 1, 0, -1};
int n, m;
int grid[MAX_NM][MAX_NM];

int ans = 0;

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<m;
}

void Sum1(int x, int y) {


    for(int d=0; d<DIR_NUM; d++) {
        int sum = grid[x][y];

        int nx = x+dx[d], ny = y+dy[d];
        int nx2 = x+dx[(d+1)%DIR_NUM], ny2 = y+dy[(d+1)%DIR_NUM];

        if (InRange(nx, ny)) {
            sum += grid[nx][ny];
        }

        if (InRange(nx2, ny2)) {
            sum += grid[nx2][ny2];
        }

        ans = max(ans, sum);

    }
}

void Sum2(int x, int y) {
    for(int d=0; d<2; d++) {
        int sum = grid[x][y];

        int nx = x+dx[d], ny = y+dy[d];
        int nx2 = x+dx[(d+2)%DIR_NUM], ny2 = y+dy[(d+2)%DIR_NUM];

        if (InRange(nx, ny)) {
            sum += grid[nx][ny];
        }

        if (InRange(nx2, ny2)) {
            sum += grid[nx2][ny2];
        }

        ans = max(ans, sum);
    }
}

int main() {
    cin >> n>>m;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            Sum1(i, j);
            Sum2(i, j);
        }
    }

    cout << ans;
    return 0;
}