#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
#define MAX_NM 100
#define DIR_NUM 4

int n, m;
int grid[MAX_NM][MAX_NM];
bool visited[MAX_NM][MAX_NM];
queue<pair<int, int>> q;

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<m;
}

bool CanGO(int x, int y) {
    if(!InRange(x, y)) return false;
    if(visited[x][y] || grid[x][y] == 0) return false;

    return true;
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
            if(CanGO(nx, ny)) {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = 1;
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

    q.push(make_pair(0, 0));
    visited[0][0] = 1;
    BFS();

    cout << visited[n-1][m-1];
    return 0;
}