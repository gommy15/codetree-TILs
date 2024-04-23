#include <iostream>
#include <utility>
#include <tuple>
using namespace std;

#define MAX_N 100
#define ASCII_NUM 128
#define DIR_NUM 4
#define OUT_OF_GRID make_pair(-1, -1)

int n, m;
int x, y;

int grid[MAX_N][MAX_N];

// 주사위 상태
int u=1, f=2, r=3;

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

pair<int, int> NextPos(int x, int y, int move_dir) {
    int dx[DIR_NUM] = {0, 0, -1, 1};
    int dy[DIR_NUM] = {1, -1, 0, 0};
    int nx = x+dx[move_dir], ny=y+dy[move_dir];
    if(InRange(nx, ny))
        return make_pair(nx, ny);
    else
        return OUT_OF_GRID;
}

void Simulate(int move_dir) {
    // move_dir 방향으로 굴렸을 때의 격자상의 위치 확인
    pair<int, int> next_pos = NextPos(x, y, move_dir);

    // 굴리는게 불가능하다면 패스
    if(next_pos == OUT_OF_GRID) return;

    tie(x, y) = next_pos;

    if(move_dir == 0) // 동쪽
        tie(u, f, r) = make_tuple(7-r, f, u);
    else if (move_dir == 1) // 서쪽
        tie(u, f, r) = make_tuple(r, f, 7-u);
    else if (move_dir == 2) // 북쪽
        tie(u, f, r) = make_tuple(f, 7-u, r);
    else // 남쪽
        tie(u, f, r) = make_tuple(7-f, u, r);

    // 바닥 숫자 변경
    int down = 7-u;
    grid[x][y] = down;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m>>x>>y;
    x--;
    y--;

    int dir_mapper[ASCII_NUM];
    dir_mapper['R'] = 0;
    dir_mapper['L'] = 1;
    dir_mapper['U'] = 2;
    dir_mapper['D'] = 3;

    grid[x][y] = 6;
    for(int i=0; i<m; i++) {
        char char_dir;
        cin >> char_dir;

        Simulate(dir_mapper[char_dir]);
    }

    int ans = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            ans += grid[i][j];
        }
    }

    cout << ans;
    return 0;
}