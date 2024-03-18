#include <iostream>
using namespace std;
#define MAX_NM 100
#define SHIFT_RIGHT 0
#define SHIFT_LEFT 1
#define DIR_NUMS 4

int n, m, q;

int grid[MAX_NM+1][MAX_NM+1];
int dx[DIR_NUMS] = {0, 1, 0, -1}, dy[DIR_NUMS] = {1, 0, -1, 0};

void Shift(int r1, int c1, int r2, int c2) {
    // 오른쪽 윗단 꼭지점부터 시계방향으로 임의의 값 저장
    int tmp1 = grid[r1][c2];
    int tmp2 = grid[r2][c2];
    int tmp3 = grid[r2][c1];
    
    // 1. 맨 윗단 왼쪽에서 오른쪽으로
    for(int col = c2; col>c1; col--) {
        grid[r1][col] = grid[r1][col-1];
    }
    
    // 2. 오른쪽 위에서 아래로
    for(int row=r2; row>r1+1; row--) {
        grid[row][c2] = grid[row-1][c2];
    }
    grid[r1+1][c2] = tmp1;

    // 3. 맨 아랫단 오른쪽에서 왼쪽으로
    for(int col = c1; col<c2-1; col++) {
        grid[r2][col] = grid[r2][col+1];
    }
    grid[r2][c2-1] = tmp2;

    // 4. 왼쪽 아래에서 위로
    for(int row = r1; row<r2-1; row++) {
        grid[row][c1] = grid[row+1][c1];
    }
    grid[r2-1][c1] = tmp3;
    
}

bool InRange(int x, int y) {
    return 1<=x && x<=n && 1<=y && y<=m;
}

int Avg(int x, int y) {
    int sum = grid[x][y];
    int cnt = 1;
    for(int i=0; i<DIR_NUMS; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(!InRange(nx, ny)) continue;
        sum += grid[nx][ny];
        cnt++;
    }

    return sum/cnt;
}

void SetAvg(int r1, int c1, int r2, int c2) {
    int tmp[MAX_NM+1][MAX_NM+1];
    for(int i=r1; i<=r2; i++) {
        for(int j=c1; j<=c2; j++) {
            tmp[i][j] = Avg(i, j);
        }
    }

    for(int i=r1; i<=r2; i++) {
        for(int j=c1; j<=c2; j++) {
            grid[i][j] = tmp[i][j];
        }
    }
}

void Simulate(int r1, int c1, int r2, int c2) {
    Shift(r1, c1, r2, c2);

    // for(int i=1; i<=n; i++) {
    //     for(int j=1; j<=m; j++) {
    //         cout << grid[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    SetAvg(r1, c1, r2, c2);
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m>>q;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> grid[i][j];
        }
    }

    while(q--) {
        int r1, c1, r2, c2;
        cin >> r1>>c1>>r2>>c2;

        Simulate(r1, c1, r2, c2);
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}