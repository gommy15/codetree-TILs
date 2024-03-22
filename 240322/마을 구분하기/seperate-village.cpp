#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 25
#define DIR_NUM 4

int n;
int graph[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int ans[MAX_N*MAX_N];
int cnt = 0;

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

bool CanGo(int x, int y) {
    if(!InRange(x, y)) return false;
    if(graph[x][y] == 0 || visited[x][y] == 1) return false;
    return true;
}

void DFS(int vertex_x, int vertex_y) {
    int dx[DIR_NUM] = {0, -1, 0, 1};
    int dy[DIR_NUM] = {1, 0, -1, 0};

    visited[vertex_x][vertex_y] = 1;

    for(int i=0; i<DIR_NUM; i++) {
        int nx = vertex_x+dx[i], ny = vertex_y+dy[i];
        if(CanGo(nx, ny)) {
            cnt++;
            DFS(nx, ny);
        }
    }

}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> graph[i][j];
        }
    }

    int idx = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(visited[i][j] != 1 && graph[i][j] != 0) {
                cnt = 1;
                DFS(i, j);
                ans[idx++] = cnt;
            }
        }
    }

    sort(ans, ans+idx);
    cout << idx << '\n';
    for(int i=0; i<idx; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}