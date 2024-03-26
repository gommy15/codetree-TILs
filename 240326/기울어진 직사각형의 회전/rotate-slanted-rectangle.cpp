#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 100
#define DIR_NUM 4
#define CCW 0
#define CW 1

int n;
int grid[MAX_N][MAX_N];
int tmp[MAX_N][MAX_N];

void Shift(int x, int y, int k, int l, int move_dir) {
    vector<int> dx, dy, move_nums;

    if(move_dir == CCW) {
        dx = {-1, -1, 1, 1};
        dy = {1, -1, -1, 1};
        move_nums = {k, l, k, l};
    } else {
        dx = {-1, -1, 1, 1};
        dy = {-1, 1, 1, -1};
        move_nums = {l, k, l, k};
    }

    // 1. tmp 배열에 grid값 복사
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            tmp[i][j] = grid[i][j];
        }
    }

    // 2. 기울어진 직사각형의 경계를 따라가면서 숫자를 한 칸씩 밀었을 때의 결과를 tmp에 저장
    for(int d=0; d<DIR_NUM; d++) {
        for(int q=0; q<move_nums[d]; q++) {
            int nx = x+dx[d], ny = y+dy[d];
            tmp[nx][ny] = grid[x][y];
            x = nx;
            y = ny;
        }
    }

    // 3. tmp 값을 grid에 복사
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            grid[i][j] = tmp[i][j];
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

    int x, y, m1, m2, m3, m4, d;
    cin >>x>>y>>m1>>m2>>m3>>m4>>d;

    Shift(x-1, y-1, m1, m2, d);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }


    return 0;
}