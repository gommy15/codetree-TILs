#include <bits/stdc++.h>
using namespace std;

#define MAX_NM 50
#define DIR_num 4

int n, m;
int grid[MAX_NM][MAX_NM];
bool visited[MAX_NM][MAX_NM];

int max_k, ans_k, max_save, save_c;

bool CanGo(int x, int y, int k) {
    return 0<=x && x<n && 0<=y && y<m && grid[x][y] > k && !visited[x][y];
}

void DFS(int x, int y, int k) {
    int dx[DIR_num] = {-1, 0, 1, 0};
    int dy[DIR_num] = {0, 1, 0, -1};

    for(int d=0; d<DIR_num; d++) {
        int nx = x+dx[d], ny = y+dy[d];

        if(CanGo(nx, ny, k)) {
            visited[nx][ny] = true;
            DFS(nx, ny, k);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n>>m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> grid[i][j];

            max_k = max(max_k, grid[i][j]);
        }
    }

    for(int k=1; k<max_k; k++) {
        save_c = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                visited[i][j] = false;
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] > k && !visited[i][j]) {
                    visited[i][j] = true;
                    DFS(i, j, k);
                    save_c++;
                }
            }
        }

        if(save_c > max_save) {
            max_save = save_c;
            ans_k = k;
        }
    }

    cout << ans_k << ' ' << max_save;
    return 0;
}