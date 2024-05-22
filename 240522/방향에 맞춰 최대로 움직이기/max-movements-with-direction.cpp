#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 4
#define DIR_NUM 8

int n, r, c, ans;
int grid[MAX_N][MAX_N];
int direc[MAX_N][MAX_N];
int dx[DIR_NUM] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[DIR_NUM] = {0, 1, 1, 1, 0, -1, -1, -1};

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

bool CanGo(int x, int y, int prev_num) {
    return InRange(x, y) && grid[x][y] > prev_num;
}

void FindMax(int x, int y, int cnt) {
    // 최댓값 갱신
    ans = max(ans, cnt);
    
    int d = direc[x][y]-1;

    for(int i=0; i<n; i++) {
        int nx = x+dx[d]*i, ny = y+dy[d]*i;
        if(CanGo(nx, ny, grid[x][y]))
            FindMax(nx, ny, cnt+1);
    }



}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> direc[i][j];
        }
    }


    cin >> r>>c;

    FindMax(r-1, c-1, 0);

    cout << ans;
    return 0;
}