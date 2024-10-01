#include <iostream>
#include <algorithm>
using namespace std;
#define DIR_NUM 4
#define MAX_NM 200

int n, m, ans;
int grid[MAX_NM][MAX_NM];
int dx[DIR_NUM] = {-1, 0, 1, 0}, dy[DIR_NUM] = {0, 1, 0, -1};

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

int FindMax(int x, int y) {
    int num = grid[x][y];
    int sum = 0;

    for(int d=0; d<DIR_NUM; d++) {
        int nx1 = x+dx[d], ny1 = y+dy[d];
        int nx2 = x+dx[(d+1)%4], ny2 = y+dy[(d+1)%4];
        if(!InRange(nx1, ny1) || !InRange(nx2, ny2)) continue;

        sum = max(sum, num+grid[nx1][ny1]+grid[nx2][ny2]);
    }

    for(int d=0; d<2; d++) {
        int nx1 = x+dx[d], ny1 = y+dy[d];
        int nx2 = x+dx[(d+2)%4], ny2 = y+dy[(d+2)%4];
        if(!InRange(nx1, ny1) || !InRange(nx2, ny2)) continue;

        sum = max(sum, num+grid[nx1][ny1]+grid[nx2][ny2]);
    }

    return sum;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            ans = max(ans, FindMax(i, j));
        }
    }

    cout << ans;

    return 0;
}