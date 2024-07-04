#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <climits>
using namespace std;

#define MAX_N 100
#define DIR_NUM 4

int n, k;
int step[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N], grid[MAX_N][MAX_N];
int r1, c1, r2, c2;

vector<pair<int, int>> wall_pos, selected_wall;
queue<pair<int, int>> q;

int ans = INT_MAX;

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

bool CanGo(int x, int y) {
    return InRange(x, y) && !visited[x][y] && !grid[x][y];
}

void Push(int x, int y, int num) {
    step[x][y] = num;
    visited[x][y] = 1;
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

int Calc() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            step[i][j] = 0;
            visited[i][j] = 0;
        }
    }

    for(int i=0; i<selected_wall.size(); i++) {
        int x, y;
        tie(x, y) = selected_wall[i];
        grid[x][y] = 0;
    }

    Push(r1, c1, 0);
    BFS();

    for(int i=0; i<selected_wall.size(); i++) {
        int x, y;
        tie(x, y) = selected_wall[i];
        grid[x][y] = 1;
    }

    if(visited[r2][c2])
        return step[r2][c2];
    else
        return INT_MAX;
}

void FindMinMove(int idx, int cnt) {
    if (idx == wall_pos.size()) {
        if(cnt == k) {
            ans = min(ans, Calc());
        }
        return;
    }

    selected_wall.push_back(wall_pos[idx]);
    FindMinMove(idx+1, cnt+1);
    selected_wall.pop_back();

    FindMinMove(idx+1, cnt);
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>k;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
            if(grid[i][j])
                wall_pos.push_back(make_pair(i, j));
        }
    }

    cin >> r1>>c1>>r2>>c2;
    r1--; r2--; c1--; c2--;

    FindMinMove(0, 0);

    if(ans == INT_MAX)
        cout << -1;
    else 
        cout << ans;

    return 0;
}