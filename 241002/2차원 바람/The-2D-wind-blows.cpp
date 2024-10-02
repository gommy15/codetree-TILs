#include <iostream>
using namespace std;
#define MAX_NM 100
#define DIR_NUM 4

int n, m, q;
int grid[MAX_NM][MAX_NM], tmp[MAX_NM][MAX_NM];

void Shift(int r1, int c1, int r2, int c2) {
    //가로 위
    for(int j=c1+1; j<=c2; j++) {
        tmp[r1][j] = grid[r1][j-1];
    }

    // 세로 오른쪽
    for(int i=r1+1; i<=r2; i++) {
        tmp[i][c2] = grid[i-1][c2];
    }

    // 가로 아래
    for(int j=c1; j<c2; j++) {
        tmp[r2][j] = grid[r2][j+1];
    }

    // 세로 왼쪽
    for(int i=r1; i<r2; i++) {
        tmp[i][c1] = grid[i+1][c1];
    }
}

void Synk() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            grid[i][j] = tmp[i][j];
        }
    }
}

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<m;
}

void AverNum(int r1, int c1, int r2, int c2) {
    int dx[DIR_NUM] = {-1, 0, 1, 0};
    int dy[DIR_NUM] = {0, 1, 0, -1};

    for(int i=r1; i<=r2; i++) {
        for(int j=c1; j<=c2; j++) {
            int sum = grid[i][j], cnt = 1;
            for(int d=0; d<DIR_NUM; d++) {
                int nx = i+dx[d], ny = j+dy[d];
                if(!InRange(nx, ny)) continue;

                sum += grid[nx][ny];
                cnt++;
            }

            tmp[i][j] = sum/cnt;
        }
    }
}

void Simulate(int sr, int sc, int er, int ec) {
    Shift(sr, sc, er, ec);

    Synk();

    AverNum(sr, sc, er, ec);

    Synk();
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m>>q;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> grid[i][j];
            tmp[i][j] = grid[i][j];
        }
    }

    while (q--) {
        int r1, c1, r2, c2;
        cin >> r1>>c1>>r2>>c2;

        Simulate(r1-1, c1-1, r2-1, c2-1);
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}