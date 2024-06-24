#include <iostream>
#include <utility>
#include <tuple>
using namespace std;
#define MAX_N 20
#define DIR_NUM 8

int n, m;
pair<int, int> nums_spot[MAX_N*MAX_N+1];
int grid[MAX_N][MAX_N];

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

int FindMaxSpot(int num) {
    int dx[DIR_NUM] = {0, -1, -1, -1, 0, 1, 1, 1};
    int dy[DIR_NUM] = {1, 1, 0, -1, -1, -1, 0, 1};

    int x, y;
    tie(x, y) = nums_spot[num];
    int max_num = 0;
    for(int d=0; d<DIR_NUM; d++) {
        int nx = x+dx[d], ny=y+dy[d];

        if(!InRange(nx, ny)) continue;

        if(grid[nx][ny] > max_num)
            max_num = grid[nx][ny];
    }

    return max_num;
}

void Simulate() {
    int tmp, tx, ty, x, y;
    for(int i=1; i<=n*n; i++) {
        tmp = FindMaxSpot(i);
        tie(tx, ty) = nums_spot[tmp];
        tie(x, y) = nums_spot[i];

        grid[tx][ty] = i;
        grid[x][y] = tmp;

        nums_spot[tmp] = nums_spot[i];
        nums_spot[i] = make_pair(tx, ty);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
            nums_spot[grid[i][j]] = make_pair(i, j);
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