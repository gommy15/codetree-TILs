#include <iostream>
#include <queue>
using namespace std;

#define MAX_N 100
#define DIR_NUM 4

int n, k;
int grid[MAX_N][MAX_N];

queue<pair<int, int>> bfs_q;
bool visited[MAX_N][MAX_N];

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

bool CanGo(int x, int y) {
    if(!InRange(x, y)) return false;
    if(visited[x][y] || grid[x][y]) return false;

    return true;
}

void BFS() {
    int dx[DIR_NUM] = {-1, 1, 0, 0};
    int dy[DIR_NUM] = {0, 0, -1, 1};

    while(!bfs_q.empty()) {
        pair<int, int> curr_pos = bfs_q.front();
        bfs_q.pop();
        int x = curr_pos.first;
        int y = curr_pos.second;

        for(int d=0; d<DIR_NUM; d++) {
            int nx = x+dx[d], ny = y+dy[d];

            if(CanGo(nx, ny)) {
                visited[nx][ny] = 1;
                bfs_q.push(make_pair(nx, ny));
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>k;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    while(k--) {
        int x, y;
        cin >> x>>y;
        bfs_q.push(make_pair(x-1, y-1));
        visited[x-1][y-1] = 1;
    }

    BFS();

    int ans= 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(visited[i][j])
                ans++;
        }
    }

    cout << ans;
    return 0;
}