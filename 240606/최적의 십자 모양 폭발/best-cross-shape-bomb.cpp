#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 50
#define DIR_NUM 4

int n, ans;
int grid[MAX_N][MAX_N], tmp[MAX_N][MAX_N];

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

void Bumb(int x, int y, int k) {
    int dx[DIR_NUM] = {0, -1, 0, 1};
    int dy[DIR_NUM] = {1, 0, -1, 0};

    for(int i=0; i<k; i++) {
        for(int d=0; d<DIR_NUM; d++) {
            int nx = x+dx[d]*i, ny=y+dy[d]*i;

            if(!InRange(nx, ny) && tmp[nx][ny] == 0) continue;

            tmp[nx][ny] = 0;
        }
    }
}

void Drop() {
    int tmp_next[MAX_N][MAX_N] = {};

    for(int col=0; col<n; col++) {
        int cnt = n-1;
        for(int row=n-1; row>=0; row--) {
            if(tmp[row][col] != 0)
                tmp_next[cnt--][col] = tmp[row][col];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            tmp[i][j] = tmp_next[i][j];
        }
    }
}

int CountMatch() {
    int cnt = 0;

    // 가로 카운트
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-1; j++) {
            if(tmp[i][j] != 0 && tmp[i][j] == tmp[i][j+1]) cnt++;
        }
    }

    // 세로 카운트
    for(int j=0; j<n; j++) {
        for(int i=0; i<n-1; i++) {
            if(tmp[i][j] != 0 && tmp[i][j] == tmp[i+1][j]) cnt++;
        }
    }

    return cnt;
}

int BumbMatch(int x, int y) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            tmp[i][j] =grid[i][j];
        }
    }

    Bumb(x, y, grid[x][y]);
    Drop();
    return CountMatch();
}

void Simulate() {
    int cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cnt = BumbMatch(i, j);
            ans = max(ans, cnt);
        }
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

    Simulate();

    cout << ans;
    
    return 0;
}