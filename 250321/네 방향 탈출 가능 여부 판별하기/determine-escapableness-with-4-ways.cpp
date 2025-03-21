#include <bits/stdc++.h>
using namespace std;
#define MAX_NM 100
#define DIR_NUM 4

int n, m;
int grid[MAX_NM][MAX_NM];
bool visited[MAX_NM][MAX_NM];

queue<pair<int, int>> q;

bool CanGo(int x, int y) {
    return 0<=x && x<n && 0<=y && y<m && grid[x][y] && !visited[x][y];
}

void BFS() {
    int dx[DIR_NUM] = {-1, 1, 0, 0};
    int dy[DIR_NUM] = {0, 0, -1, 1};

    while(!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        for(int d=0; d<DIR_NUM; d++) {
            int nx = x+dx[d], ny = y+dy[d];

            if(CanGo(nx, ny)) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
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

    visited[0][0];
    q.push({0, 0});
    BFS();

    cout << visited[n-1][m-1];
    return 0;
}