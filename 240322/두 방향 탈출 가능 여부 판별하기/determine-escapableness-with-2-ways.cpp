#include <iostream>
using namespace std;
#define MAX_NM 100

int n, m;
int grid[MAX_NM][MAX_NM];
int visited[MAX_NM][MAX_NM];
int dx[2] = {1, 0}, dy[2] = {0, 1};

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

bool CanGo(int x, int y) {
    if(!InRange(x, y)) return false;

    if(grid[x][y] == 0 || visited[x][y] == 1) return false;

    return true;
}

void DFS(int vertex_x, int vertex_y) {
    for(int i=0; i<2; i++) {
        int nx = vertex_x+dx[i], ny = vertex_y+dy[i];
        if(CanGo(nx, ny)) {
            visited[nx][ny] = 1;
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

    visited[0][0] = 1;
    DFS(0, 0);

    if(visited[0][0] && visited[n-1][n-1]) cout << 1;
    else cout << 0;

    return 0;
}