#include <iostream>
using namespace std;

#define MAX_N 100
#define DIR_NUM 4

int n, m, r, c;
int grid[MAX_N][MAX_N];
int next_grid[MAX_N][MAX_N];

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

void Expand(int x, int y, int dist) {
    int dx[DIR_NUM] = {-1, 1, 0, 0};
    int dy[DIR_NUM] = {0, 0, -1, 1};
    
    for(int i=0; i<DIR_NUM; i++) {
        int nx = x+dx[i]*dist, ny = y+dy[i]*dist;
        if(InRange(nx, ny) && next_grid[nx][ny] == 0)
            next_grid[nx][ny] = 1;
    }
}

void Simulate(int dist) {
    // 1. next_grid 값 초기화
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            next_grid[i][j] = 0;
    }

    // 2. 폭탄 던지는 시뮬레이션 실행
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(grid[i][j])
               Expand(i, j, dist); 
        }
    }

    // 3. next_grid 값 grid로 업데이트
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(next_grid[i][j]) grid[i][j] = 1;
        }
    }
}

int main() {
    cin >> n>>m>>r>>c;

    grid[r-1][c-1] = 1;

    int dist = 1;
    while(m--) {
        Simulate(dist);
        dist *= 2;
    }

    int ans = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) {
            ans += grid[i][j];
        }
    
    cout << ans;
    return 0;
}