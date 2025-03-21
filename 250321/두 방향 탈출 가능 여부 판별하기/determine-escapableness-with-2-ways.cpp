#include <bits/stdc++.h>
using namespace std;
#define MAX_NM 100
#define DIR_NUM 2

int n, m;
int grid[MAX_NM][MAX_NM];

bool visited[MAX_NM][MAX_NM];

bool CanGo(int x, int y) {
    return 0<=x && x<n && 0<=y && y<m && grid[x][y] && !visited[x][y];
}

void DFS(int x, int y) {
    int dx[DIR_NUM] = {1, 0}, dy[DIR_NUM] = {0, 1};

    for(int d=0; d<DIR_NUM; d++) {
        int nx = x+dx[d], ny = y+dy[d];

        if(CanGo(nx, ny)) {
            visited[nx][ny] = true;
            DFS(nx, ny);
        }
    }
}

int main() {
    cin >> n>>m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> grid[i][j];
        }
    }

    visited[0][0] = true;
    DFS(0, 0);

    cout << visited[n-1][m-1];
    return 0;
}