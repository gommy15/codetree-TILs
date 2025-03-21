#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100
#define DIR_NUM 4
#define NOT_EXISTS make_pair(-1, -1)

int n, k;
int grid[MAX_N][MAX_N];
pair<int, int> curr_cell;

queue<pair<int, int>> q;
bool visited[MAX_N][MAX_N];

bool CanGo(int x, int y, int num) {
    return 0<=x && x<n && 0<=y && y<n && !visited[x][y] && grid[x][y] < num;
}

void BFS() {
    int dx[DIR_NUM] = {-1, 0, 1, 0};
    int dy[DIR_NUM] = {0, 1, 0, -1};

    int x, y;
    tie(x, y) = curr_cell;
    visited[x][y] = true;
    q.push(curr_cell);

    int target_n = grid[x][y];

    while(!q.empty()) {
        tie(x, y) = q.front();
        q.pop();

        for(int i=0; i<DIR_NUM; i++) {
            int nx = x+dx[i], ny = y+dy[i];

            if(CanGo(nx, ny, target_n)) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

bool NeedUpDate(pair<int, int> best_pos, pair<int, int> new_pos) {
    if(best_pos == NOT_EXISTS) return true;

    int bx, by;
    tie(bx, by) = best_pos;

    int nx, ny;
    tie(nx, ny) = new_pos;

    return make_tuple(grid[nx][ny], -nx, -ny) > make_tuple(grid[bx][by], -bx, -by);
}

bool Move() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            visited[i][j] = false;
        }
    }

    BFS();

    pair<int, int> best_pos = NOT_EXISTS;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(!visited[i][j] || make_pair(i, j) == curr_cell) continue;

            pair<int, int> new_pos = {i, j};
            if(NeedUpDate(best_pos, new_pos))
                best_pos = new_pos;
        }
    }

    if(best_pos == NOT_EXISTS) return false;
    else {
        curr_cell = best_pos;
        return true;
    }
}

int main() {
    cin >> n>>k;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    int r, c;
    cin >> r>>c;
    curr_cell = {r-1, c-1};

    while(k--) {
        bool is_moved = Move();

        if(!is_moved) break;
    }

    int x, y;
    tie(x, y) = curr_cell;
    cout << x+1 << ' ' << y+1;

    return 0;
}