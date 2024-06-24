#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
using namespace std;
#define MAX_N 20
#define DIR_NUM 4

int n, m;
int grid[MAX_N][MAX_N], exist[MAX_N][MAX_N];
vector<pair<int, int>> ball;

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

pair<int, int> Move_spot(pair<int, int> og) {
    int dx[DIR_NUM] = {-1, 1, 0, 0};
    int dy[DIR_NUM] = {0, 0, -1, 1};

    int x, y;
    tie(x, y) = og;
    int max_num = 0;
    int next_x = 0, next_y = 0;

    for(int d=0; d<DIR_NUM; d++) {
        int nx = x+dx[d], ny = y+dy[d];

        if(!InRange(nx, ny)) continue;

        if(grid[nx][ny] > max_num) {
            next_x = nx;
            next_y = ny;
            max_num = grid[nx][ny]; 
        }
    }

    return make_pair(next_x, next_y);

}

void Simulate() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            exist[i][j] = 0;
        }
    }

    int x, y;
    for(int i=0; i<ball.size(); i++) {
        tie(x, y) = Move_spot(ball[i]);

        exist[x][y]++;
    }

    ball.clear();

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            // cout << exist[i][j] << ' ';
            if(exist[i][j] == 1)
                ball.push_back(make_pair(i, j));
        }
        // cout << '\n';
    }
}


int main() {
    // 여기에 코드를 작성해주세요.
    int t;
    cin >> n>>m>>t;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    int r, c;
    for(int i=0; i<m; i++) {
        cin >>r>>c;
        ball.push_back(make_pair(r-1, c-1));
    }

    while(t--) {
        Simulate();
    }

    cout << ball.size();

    return 0;
}