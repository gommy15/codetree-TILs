#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;
#define MAX_NM 100
#define DIR_NUM 4

int n, m;
int step[MAX_NM][MAX_NM];
bool grid[MAX_NM][MAX_NM], visited[MAX_NM][MAX_NM];
queue<pair<int, int>> q;

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<m;
}

bool CanGo(int x, int y) {
    if(!InRange(x, y)) return false;
    if(visited[x][y] || grid[x][y] == 0) return false;

    return true;
}

void Push(int x, int y, int num) {
    step[x][y] = num;
    visited[x][y] = true;
    q.push(make_pair(x, y));
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
                Push(nx, ny, step[x][y]+1);
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

    Push(0, 0, 0);

    BFS();

    if(visited[n-1][m-1]) cout << step[n-1][m-1];
    else cout << -1;
    return 0;
}