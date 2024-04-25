#include <iostream>
#define MAX_N 20
#define DIR_NUM 4
using namespace std;

int n, m, t;
int grid[MAX_N][MAX_N];
int place[MAX_N][MAX_N], new_place[MAX_N][MAX_N];

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

void Move(int x, int y) {
    int dx[DIR_NUM] = {-1, 1, 0, 0};
    int dy[DIR_NUM] = {0, 0, -1, 1};

    int max_num = grid[x][y];
    int next_x = x, next_y = y;
    for(int i=0; i<DIR_NUM; i++) {
        int nx = x+dx[i], ny=y+dy[i];

        if(!InRange(nx, ny)) continue;

        if(grid[x][y] == grid[nx][ny] || max_num < grid[nx][ny]) {
            max_num = grid[nx][ny];
            next_x = nx;
            next_y = ny;
        }
    }

    new_place[next_x][next_y]++;
}

void Simulate() {
    // 이동할 곳을 확인하는 배열 초기화
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            new_place[i][j] = 0;
        }
    }

    // 구슬 위치 확인 후 이동
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(place[i][j] == 1)
                Move(i, j);
        }
    }

    // 충돌 구슬 제외 후 구슬 위치 복사
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(new_place[i][j] == 1) place[i][j] = 1;
            else place[i][j] = 0;
            // cout << place[i][j] << ' ';
        }
        // cout << '\n';
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m>>t;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i=0; i<m; i++) {
        int r, c;
        cin >>r>>c;
        place[r-1][c-1] = 1;
    }

    while(t--) {
        Simulate();
        // cout << '\n';
    }

    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            // cout << place[i][j] << ' ';
            ans += place[i][j];
        }
        // cout << '\n';
    }

    cout << ans;
    return 0;
}