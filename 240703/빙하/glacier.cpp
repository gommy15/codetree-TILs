#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

enum ELEMENT{
    WATER,
    GLACIER
};

#define DIR_NUM 4
#define MAX_NM 200

int n, m;
int grid[MAX_NM][MAX_NM];
queue<pair<int, int>> q;
bool visited[MAX_NM][MAX_NM];
int cnt;

int dx[DIR_NUM] = {1, -1, 0, 0};
int dy[DIR_NUM] = {0, 0, 1, -1};

int elapsed_time, last_melt_cnt;

void Initialize() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            visited[i][j] = 0;
        }
    }
}

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<m;
}

bool CanGo(int x, int y) {
    if(!InRange(x, y)) return false;
    if(visited[x][y] || grid[x][y]) return false;

    return true;
}

void BFS() {
    Initialize();

    q.push(make_pair(0, 0));
    visited[0][0] = true;

    while(!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        for(int d=0; d<DIR_NUM; d++) {
            int nx = x+dx[d], ny = y+dy[d];

            if(CanGo(nx, ny)) {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
        }
    }
}

bool OutsideWaterExistInNeighbor(int x, int y) {
    for(int d=0; d<DIR_NUM; d++) {
        int nx = x+dx[d], ny = y+dy[d];
        if(InRange(nx, ny) && visited[nx][ny])
            return true;
    }

    return false;
}

void Melt() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j] == GLACIER && OutsideWaterExistInNeighbor(i, j)) {
                grid[i][j] = WATER;
                last_melt_cnt++;
            }
        }
    }
}

void Simulate() {
    elapsed_time++;
    last_melt_cnt = 0;

    BFS();
    
    Melt();
}

bool GlacierExist() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j] == GLACIER)
                return true;
        }
    }

    return false;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> grid[i][j];
        }
    }

    do {
        Simulate();
    } while(GlacierExist());

    cout << elapsed_time << ' ' << last_melt_cnt;
    return 0;
}