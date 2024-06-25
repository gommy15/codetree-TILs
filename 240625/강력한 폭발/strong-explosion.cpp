#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <tuple>
using namespace std;
#define MAX_N 20
#define BOMB_TYPE_NUM 3

int n, ans;
bool bombed[MAX_N][MAX_N];
int bomb_type[MAX_N][MAX_N];
vector<pair<int, int>> bombs;
pair<int, int> bomb_shapes[BOMB_TYPE_NUM+1][5] = {
    {},
    {{-2, 0}, {-1, 0}, {0, 0}, {1, 0}, {2, 0}},
    {{-1, 0}, {0, -1}, {0, 0}, {0, 1}, {1, 0}},
    {{-1, -1}, {-1, 1}, {0, 0}, {1, -1}, {1, 1}}
};

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

void Bomb(int x, int y, int type) {
    for(int i=0; i<5; i++) {
        int dx, dy;
        tie(dx, dy) = bomb_shapes[type][i];

        int nx = x+dx, ny = y+dy;
        if(InRange(nx, ny)) bombed[nx][ny] = true;
    }
}

int Calc() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(bomb_type[i][j])
                Bomb(i, j, bomb_type[i][j]);
        }
    }

    int cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(bombed[i][j]) {
                cnt++;
                bombed[i][j] = false;
            }
        }
    }

    return cnt;
}

void Simulate(int cnt) {
    if(cnt == (int)bombs.size()) {
        ans = max(ans, Calc());
        return;
    }

    for(int i=1; i<=3; i++) {
        int x, y;
        tie(x, y) = bombs[cnt];

        bomb_type[x][y] = i;
        Simulate(cnt+1);
        bomb_type[x][y] = 0;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int bomb_place;
            cin >> bomb_place;
            if(bomb_place) bombs.push_back(make_pair(i, j));
        }
    }

    Simulate(0);

    cout << ans;
    return 0;
}