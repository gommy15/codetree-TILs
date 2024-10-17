#include <iostream>
#include <vector>
using namespace std;
#define MAX_NM 100

int n, m;
int grid[MAX_NM][MAX_NM];
bool visited[MAX_NM][MAX_NM];

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<m;
}

bool CanGo(int x, int y) {
    if(!InRange(x, y)) return false;
    if(visited[x][y] || grid[x][y] == 0) return false;

    return true;
}

void DFS(int x, int y) {
    int dx[2] = {1, 0};
    int dy[2] = {0, 1};

    for(int d=0; d<2; d++) {
        int nx = x+dx[d];
        int ny = y+dy[d];

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
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    visited[0][0] = 1;
    DFS(0, 0);

    cout << visited[n-1][m-1];
    return 0;
}