#include <iostream>
#include <utility>
#include <tuple>
using namespace std;
#define MAX_N 20
#define DIR_NUM 8

int n, m;
int grid[MAX_N][MAX_N];
pair<int, int> dots[MAX_N+1];

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

pair<int, int> FindMaxNum(int x, int y) {
    int dx[DIR_NUM] = {0, -1, -1, -1, 0, 1, 1, 1};
    int dy[DIR_NUM] = {1, 1, 0, -1, -1, -1, 0, 1};

    int max_num = 0;
    int next_x, next_y;
    for(int i=0; i<DIR_NUM; i++) {
        int nx=x+dx[i], ny=y+dy[i];

        if(!InRange(nx, ny)) continue;

        if(max_num < grid[nx][ny]) {
            max_num = grid[nx][ny];
            next_x = nx;
            next_y = ny;
        }
    }

    return make_pair(next_x, next_y);
}

void Simulate() {
    for(int num=1; num<=n*n; num++) {
        int x, y;
        tie(x, y) = dots[num];
        int mx, my;
        tie(mx, my) = FindMaxNum(x, y);
        int max_num = grid[mx][my];

        // cout << num << ' ' << max_num << '\n';
        // cout << "*********************\n";
        // cout << x << ' ' << y << '\n';
        // cout << mx << ' ' << my << '\n';
        // cout << "*********************\n";

        dots[num] = make_pair(mx, my);
        dots[max_num] = make_pair(x, y);

        grid[mx][my] = num;
        grid[x][y] = max_num;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
            dots[grid[i][j]] = make_pair(i, j);
        }
    }

    while(m--) {
        Simulate();
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}