#include <iostream>
#include <cstdlib>
using namespace std;
#define MAX_N 100
#define DIR_NUM 4

int n;
int curr_x, curr_y, curr_dir;
char grid[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N][DIR_NUM];
int dx[DIR_NUM] = {0, 1, 0, -1}, dy[DIR_NUM] = {1, 0, -1, 0};

int ans = 0;

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

bool WallExist(int x, int y) {
    return InRange(x, y) && grid[x][y] == '#';
}

void Simulate() {
    if(visited[curr_x][curr_y][curr_dir]) {
        cout << -1;
        exit(0);
    }

    visited[curr_x][curr_y][curr_dir] = true;

    int nx = curr_x+dx[curr_dir];
    int ny = curr_y+dy[curr_dir];

    if(WallExist(nx, ny)) {
        curr_dir = (curr_dir-1+4)%4;
    } else if (!InRange(nx, ny)) {
        curr_x = nx;
        curr_y = ny;
        ans++;
    } else {
        int rx = nx+dx[(curr_dir+1)%4];
        int ry = ny+dy[(curr_dir+1)%4];

        if(WallExist(rx, ry)) {
            curr_x = nx;
            curr_y = ny;
            ans++;
        } else {
            curr_x = rx;
            curr_y = ry;
            curr_dir = (curr_dir+1)%4;
            ans += 2;
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>curr_x>>curr_y;
    curr_dir = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }
    curr_x--;
    curr_y--;

    do {
        Simulate();
    } while(InRange(curr_x, curr_y));

    cout << ans;
    return 0;
}