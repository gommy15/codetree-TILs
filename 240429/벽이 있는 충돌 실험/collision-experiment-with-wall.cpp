#include <iostream>
#include <tuple>
#include <vector>

#define MAX_N 50
#define DIR_NUM 4
#define ASKII 128
using namespace std;

int marble_cnt[MAX_N+1][MAX_N+1];
vector<tuple<int, int, int>> marbles;
int mapper[ASKII];

int dx[DIR_NUM] = {-1, 0, 0, 1};
int dy[DIR_NUM] = {0, 1, -1, 0};

int t, n, m;

bool InRange(int x, int y) {
    return 1<=x && x<=n && 1<=y && y<=n;
}

tuple<int, int, int> Move(tuple<int, int, int> marble) {
    int x, y, dir;
    tie(x, y, dir) = marble;

    int nx = x+dx[dir], ny = y+dy[dir];

    if(InRange(nx, ny))
        return make_tuple(nx, ny, dir);
    else
        return make_tuple(x, y, 3-dir);
}

void MoveAll() {
    for(int i=0; i<(int)marbles.size(); i++) {
        marbles[i] = Move(marbles[i]);
    }
}

bool DuplicateMarbles(int tg_idx) {
    int tg_x, tg_y;
    tie(tg_x, tg_y, ignore) = marbles[tg_idx];

    return marble_cnt[tg_x][tg_y] >= 2;
}

void RemoveMarbles() {
    vector<tuple<int, int, int>> tmp_v;

    // 현재 구슬 위치 확인
    for(int i=0; i<(int)marbles.size(); i++) {
        int x, y;
        tie(x, y, ignore) = marbles[i];
        marble_cnt[x][y]++;
    }

    // 충돌이 일어난 구슬 제거
    for(int i=0; i<(int) marbles.size(); i++) {
        if(!DuplicateMarbles(i))
            tmp_v.push_back(marbles[i]);
    }

    // 충돌 여부 확인하는 grid 초기화
    for(int i=0; i<(int) marbles.size(); i++) {
        int x, y;
        tie(x, y, ignore) = marbles[i];
        marble_cnt[x][y]--;
    }

    // 충돌된 구슬이 제거된 리스트 복사
    marbles = tmp_v;
}

void Simulate() {
    // 1. 구슬 이동
    MoveAll();

    // 2. 움직임 이후에 충돌 구슬 제거
    RemoveMarbles();

}

int main() {
    // 여기에 코드를 작성해주세요.
    mapper['U'] = 0;
    mapper['R'] = 1;
    mapper['L'] = 2;
    mapper['D'] = 3;

    cin >> t;
    while(t--) {
        marbles.clear();

        cin >> n>>m;

        int x, y;
        char dir;
        for(int i=0; i<m; i++) {
            cin >>x>>y>>dir;
            marbles.push_back(make_tuple(x, y, mapper[dir]));
        }

        // 2*n번 이후에는 충돌이 일어날 수 없음
        for(int i=0; i<2*n; i++) {
            Simulate();
        }

        cout << (int) marbles.size() << '\n';
    }
    return 0;
}