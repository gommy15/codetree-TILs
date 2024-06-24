#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
#define MAX_N 50
#define DIR_NUM 4
#define ASCII 128

int n, m;
vector<tuple<int, int, int>> ball;
int dx[DIR_NUM] = {0, -1, 0, 1}, dy[DIR_NUM] = {1, 0, -1, 0};
int mapper[ASCII];
int ball_cnt[MAX_N][MAX_N];

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

bool CheckBall(tuple<int, int, int> target) {
    int x, y;
    tie(x, y, ignore) = target;

    return ball_cnt[x][y] == 1;
}

void Simulate() {
    int x, y, d;
    for(int i=0; i<ball.size(); i++) {
        tie(x, y, d) = ball[i];

        int nx = x+dx[d], ny = y+dy[d];

        if(!InRange(nx, ny)) {
            ball[i] = make_tuple(x, y, (d+2)%4);
            ball_cnt[x][y]++;
            continue;
        }

        ball[i] = make_tuple(nx, ny, d);
        ball_cnt[nx][ny]++;
    }

    vector<tuple<int, int, int>> tmp;

    for(int i=0; i<ball.size(); i++) {
        if(CheckBall(ball[i]))
            tmp.push_back(ball[i]);
    }

    for(int i=0; i<ball.size(); i++) {
        int x, y;
        tie(x, y, ignore) = ball[i];
        ball_cnt[x][y]--;
    }

    ball = tmp;

}


int main() {
    // 여기에 코드를 작성해주세요.
    int t;
    cin >> t;

    mapper['R'] = 0;
    mapper['U'] = 1;
    mapper['L'] = 2;
    mapper['D'] = 3;

    while(t--) {
        cin >> n>>m;

        int x, y;
        char d;
        for(int i=0; i<m; i++) {
            cin >>x>>y>>d;
            ball.push_back(make_tuple(x-1, y-1, mapper[d]));
        }

        for(int i=0; i<2*n; i++) {
            Simulate();
        }

        cout << ball.size() << '\n';
        ball.clear();
    }

    return 0;
}