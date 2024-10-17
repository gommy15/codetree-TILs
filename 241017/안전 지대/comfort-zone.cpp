#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_NM 50
#define DIR_NUM 4

int n, m;
int grid[MAX_NM][MAX_NM];
bool visited[MAX_NM][MAX_NM];

void Init_visit() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            visited[i][j] = false;
        }
    }
}

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<m;
}

bool Cango(int x, int y, int k) {
    if(!InRange(x, y)) return false;
    if(visited[x][y] || grid[x][y] <= k) return false;

    return true;
}

void DFS(int x, int y, int k) {
    int dx[DIR_NUM] = {-1, 0, 1, 0};
    int dy[DIR_NUM] = {0, -1, 0, 1};

    for(int d=0; d<DIR_NUM; d++) {
        int nx = x+dx[d];
        int ny = y+dy[d];

        if(Cango(nx, ny, k)) {
            visited[nx][ny] = true;
            DFS(nx, ny, k);
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >>n>>m;

    int max_k = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> grid[i][j];
            max_k = max(max_k, grid[i][j]);
        }
    }

    int max_saf = -1;
    int ans = 0;
    for(int k=1; k<=max_k; k++) {
        Init_visit();
        int cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] > k && visited[i][j] == false) {
                    cnt++;
                    visited[i][j] = true;
                    DFS(i, j, k);
                }
            }
        }

        // cout << "------" << cnt << '\n';

        if(max_saf < cnt) {
            max_saf = cnt;
            ans = k;
        }
    }

    cout << ans << ' ' << max_saf;
    return 0;
}