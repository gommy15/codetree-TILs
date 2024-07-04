#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;
#define MAX_N 100
#define DIR_NUM 8

int n;
int grid[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

queue<pair<int, int>> bfs_q;

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

bool CanGo(int x, int y) {
    if(!InRange(x, y)) return false;
    if(visited[x][y]) return false;

    return true;
}

void Push(int x, int y, int num) {
    grid[x][y] = num;
    visited[x][y] = 1;
    bfs_q.push(make_pair(x, y));
}

void BFS() {
    int dx[DIR_NUM] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int dy[DIR_NUM] = {2, 1, -1, -2, -2, -1, 1, 2};

    while(!bfs_q.empty()) {
        int x, y;
        tie(x, y) = bfs_q.front();
        bfs_q.pop();

        for(int d=0; d<DIR_NUM; d++) {
            int nx = x+dx[d], ny = y+dy[d];

            if(CanGo(nx, ny)) {
                Push(nx, ny, grid[x][y]+1);
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    int r1, c1, r2, c2;
    cin >> r1>>c1>>r2>>c2;

    Push(r1-1, c1-1, 0);
    BFS();

    if(visited[r2-1][c2-1]) cout << grid[r2-1][c2-1];
    else cout << -1;

    return 0;
}