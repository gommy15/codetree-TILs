#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_NM 50
#define DIR_NUM 4
#define MAX_HEIGHT 100

int n, m;
int height[MAX_NM][MAX_NM];
bool visited[MAX_NM][MAX_NM];
int dx[DIR_NUM] = {-1, 1, 0, 0}, dy[DIR_NUM] = {0, 0, -1, 1};

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<m;
}

bool CanGo(int x, int y, int k) {
    if(!InRange(x, y)) return false;
    if(visited[x][y] == 1) return false;
    if(height[x][y] <= k) return false;

    return true;
}

void DFS(int x, int y, int k) {
    for(int i=0; i<DIR_NUM; i++) {
        int nx = x+dx[i], ny = y+dy[i];

        if(CanGo(nx, ny, k)) {
            visited[nx][ny] = 1;
            DFS(nx, ny, k);
        }
    }
}


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> height[i][j];
        }
    }

    // cout << max_h << ' ' << min_h << '\n';

    int ans_k = 0, ans_n = -1;

    for(int k=1; k<=MAX_HEIGHT; k++) {
        int safe_n = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                visited[i][j] = 0;
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(CanGo(i, j, k)) {
                    safe_n++;
                    visited[i][j] = 1;
                    // cout << i << ' ' << j << '\n';
                    DFS(i, j, k);
                }
            }
        }

        // cout << "safe_n " << k << ": " << safe_n << '\n';
        // cout << "*****************\n";
        if(safe_n > ans_n) {
            ans_n = safe_n;
            ans_k = k;
        }
    }

    cout << ans_k << ' ' << ans_n;
    return 0;
}