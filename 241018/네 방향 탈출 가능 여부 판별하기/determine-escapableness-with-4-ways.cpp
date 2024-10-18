#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_NM 100
#define DIR_NUM 4

int n, m;
queue<pair<int, int>> q;
bool visited[MAX_NM][MAX_NM], grid[MAX_NM][MAX_NM];

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<m;
}

bool Cango(int x, int y) {
    if(!InRange(x, y)) return false;
    if(visited[x][y] || grid[x][y] == 0) return false;

    return true;
}

void BFS() {
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        int dx[DIR_NUM] = {-1, 0, 1, 0};
        int dy[DIR_NUM] = {0, -1, 0, 1};

        for(int d=0; d<DIR_NUM; d++) {
            int nx = x+dx[d];
            int ny = y+dy[d];

            if(Cango(nx, ny)) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> grid[i][j];
        }
    }

    visited[0][0] = true;
    q.push({0, 0});
    BFS();

    cout << visited[n-1][m-1];
    return 0;
}