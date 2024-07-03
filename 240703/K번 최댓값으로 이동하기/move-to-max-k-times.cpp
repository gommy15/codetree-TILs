#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;
#define MAX_NK 100
#define DIR_NUM 4
#define NOT_EXISTS make_pair(-1, -1)

int n, k;
int grid[MAX_NK][MAX_NK];
bool visited[MAX_NK][MAX_NK];
queue<pair<int, int>> bfs_q;
pair<int, int> cur_pos, move_pos;

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

bool CanGo(int x, int y, int num) {
    if(!InRange(x, y)) return false;
    if(visited[x][y] || grid[x][y] >= num) return false;

    return true;
}

void BFS(int num) {
    int dx[DIR_NUM] = {-1, 1, 0, 0};
    int dy[DIR_NUM] = {0, 0, -1, 1};

    while(!bfs_q.empty()) {
        int x, y;
        tie(x, y) = bfs_q.front();
        bfs_q.pop();

        for(int d=0; d<DIR_NUM; d++) {
            int nx = x+dx[d], ny = y+dy[d];

            if(CanGo(nx, ny, num)) {
                visited[nx][ny] = 1;
                bfs_q.push(make_pair(nx, ny));

                if(move_pos == NOT_EXISTS)
                    move_pos = make_pair(nx, ny);
                else {
                    int r, c;
                    tie(r, c) = move_pos;

                    if(grid[r][c] < grid[nx][ny]){
                        move_pos = make_pair(nx, ny);
                    } else if (grid[r][c] == grid[nx][ny]) {
                        if(nx < r) {
                            move_pos = make_pair(nx, ny);
                        } else if (nx == r) {
                            if(ny < c) {
                                move_pos = make_pair(nx, ny);
                            }
                        }
                    }
                }
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

    int r, c;
    cin >> r>>c;
    cur_pos = make_pair(r-1, c-1);

    while(k--) {
        move_pos = make_pair(-1, -1);
        int x, y;
        x = cur_pos.first;
        y = cur_pos.second;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                visited[i][j] = 0;
            }
        }

        visited[x][y] = 1;
        bfs_q.push(make_pair(x, y));
        BFS(grid[x][y]);

        if(move_pos == NOT_EXISTS) break;
        cur_pos = move_pos;
    }

    cout << cur_pos.first+1 << ' ' << cur_pos.second+1;
    return 0;
}