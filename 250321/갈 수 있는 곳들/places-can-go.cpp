#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100
#define DIR_NUM 4

int n, k;
int grid[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];

queue<pair<int, int>> q;

bool CanGo(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n && grid[x][y] == 0 && !visited[x][y];
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
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n>>k;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i=0; i<k; i++) {
        int r, c;
        cin >> r>>c;

        visited[r-1][c-1] = true;
        q.push({r-1, c-1});
    }

    BFS();

    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(visited[i][j]) ans++;
        }
    }

    cout << ans;

    return 0;
}