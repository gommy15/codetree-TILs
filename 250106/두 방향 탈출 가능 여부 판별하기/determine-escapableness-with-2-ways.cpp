#include <iostream>
#include <vector>
using namespace std;
#define MAX_NM 100
#define DIR_NUM 2

int n, m;
int grid[MAX_NM][MAX_NM];
bool visited[MAX_NM][MAX_NM];

int dx[DIR_NUM] = {1, 0}, dy[DIR_NUM] = {0, 1};

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<m;
}

bool CanGo(int x, int y) {
    if(!InRange(x, y)) return false;
    if(grid[x][y] == 0 || visited[x][y]) return false;

    return true;
}

void DFS(int x, int y) {

    for(int d=0; d<DIR_NUM; d++) {
        int nx = x+dx[d];
        int ny = y+dy[d];

        if(CanGo(nx, ny)) {
            visited[nx][ny] = true;
            DFS(nx, ny);
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
    DFS(0, 0);

    if(visited[n-1][m-1]) cout << 1;
    else cout << 0;
    return 0;
}