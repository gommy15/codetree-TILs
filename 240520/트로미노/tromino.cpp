#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_NM 200
#define DIR_NUM 4

int n, m, ans;
int grid[MAX_NM][MAX_NM];
int dx[DIR_NUM] = {-1, 0, 1, 0}, dy[DIR_NUM] = {0, 1, 0, -1};

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<m;
}

int TypeOne(int x, int y, int dir) {
    int sum = grid[x][y];

    for(int i=0; i<2; i++) {
        int nx = x+dx[(dir+i)%4], ny = y+dy[(dir+i)%4];

        if(!InRange(nx, ny)) return 0;

        sum += grid[nx][ny];
    }

    return sum;
}

int TypeTwo(int x, int y, int dir) {
    int sum = grid[x][y];

    for(int i=0; i<2; i++) {
        int nx = x+dx[(dir+i*2)%4], ny = y+dy[(dir+i*2)%4];

        if(!InRange(nx, ny)) return 0;

        sum += grid[nx][ny];
    }

    return sum;
}

void Simulate() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int dir=0; dir<DIR_NUM; dir++) {
                ans = max(ans, TypeOne(i, j, dir));
            }

            for(int dir=0; dir<DIR_NUM/2; dir++) {
                ans = max(ans, TypeTwo(i, j, dir));
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

    Simulate();

    cout << ans;
    return 0;
}