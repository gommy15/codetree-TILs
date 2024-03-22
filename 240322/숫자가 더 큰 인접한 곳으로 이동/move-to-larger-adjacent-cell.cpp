#include <iostream>
#define MAX_N 100
#define DIR_NUM 4
using namespace std;

int n, r, c;
int grid[MAX_N][MAX_N];
int dx[DIR_NUM] = {-1, 1, 0, 0}, dy[DIR_NUM] = {0, 0, -1, 1};

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

void Simulate(int x, int y) {
    cout << grid[x][y] << ' ';
    
    bool big_num_exist = false;
    int max_num = grid[x][y];
    int next_x, next_y;
    for(int i=0; i<DIR_NUM; i++) {
        int nx = x+dx[i], ny = y+dy[i];
        if(!InRange(nx, ny)) continue;
        if(max_num < grid[nx][ny]) {
            max_num = grid[nx][ny];
            next_x = nx;
            next_y = ny;
            big_num_exist = true;
            break;
        }
    }

    if(big_num_exist) Simulate(next_x, next_y);
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>r>>c;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    Simulate(r-1, c-1);
    return 0;
}