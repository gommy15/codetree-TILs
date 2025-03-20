#include <bits/stdc++.h>
using namespace std;
#define MAX_N 20
#define BOMB_TYPE 3

int n;
int grid[MAX_N][MAX_N];
bool bombed[MAX_N][MAX_N];

int ans;
vector<pair<int, int>> bomb_pos;

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

void Bomb(int x, int y, int k) {
    pair<int, int> bomb_shapes[BOMB_TYPE+1][5] = {
        {},
        {{-2, 0}, {-1, 0}, {0, 0}, {1, 0}, {2, 0}},
        {{-1, 0}, {1, 0}, {0, 0}, {0, -1}, {0, 1}},
        {{-1, -1}, {-1, 1}, {0, 0}, {1, -1}, {1, 1}}
    };

    for(int i=0; i<5; i++) {
        int dx, dy;
        tie(dx, dy) = bomb_shapes[k][i];

        int nx = x+dx, ny = y+dy;
        if(InRange(nx, ny))
            bombed[nx][ny] = true;
    }
}

int Calc() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            bombed[i][j] = false;
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(grid[i][j]) {
                Bomb(i, j, grid[i][j]);
            }
        }
    }

    int cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(bombed[i][j]) cnt++;
        }
    }

    return cnt;
}

void FindMaxArea(int idx) {
    if(idx == (int)bomb_pos.size()) {
        ans = max(ans, Calc());
        return;
    }

    for(int i=1; i<=3; i++) {
        int x, y;
        tie(x, y) = bomb_pos[idx];

        grid[x][y] = i;
        FindMaxArea(idx+1);
        grid[x][y] = 0;
    }
}

int main() {
    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
            if(grid[i][j]) bomb_pos.push_back(make_pair(i, j));
        }
    }

    FindMaxArea(0);

    cout << ans;
    return 0;
}