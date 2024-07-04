#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>
#include <climits>
using namespace std;
#define MAX_N 100
#define DIR_NUM 4

int n, h, m;
int a[MAX_N][MAX_N];
vector<pair<int, int>> s_pos;

queue<pair<int, int>> q;
bool visited[MAX_N][MAX_N];
int step[MAX_N][MAX_N];

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

bool CanGo(int x, int y) {
    if(!InRange(x, y)) return false;
    if(visited[x][y] || a[x][y] == 1) return false;

    return true;
}

void Push(int x, int y, int num) {
    step[x][y] = num;
    visited[x][y] = 1;
    q.push(make_pair(x, y));
}

void BFS() {
    int dx[DIR_NUM] = {-1, 1, 0, 0};
    int dy[DIR_NUM] = {0, 0, -1, 1};

    while(!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        for(int d=0; d<DIR_NUM; d++) {
            int nx = x+dx[d], ny = y+dy[d];

            if(CanGo(nx, ny)) {
                Push(nx, ny, step[x][y]+1);
            }
        }
    }
}


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>h>>m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >>  a[i][j];
            if(a[i][j] == 3)
                s_pos.push_back(make_pair(i, j));
        }
    }


    for(int i=0; i<(int)s_pos.size(); i++) {
        Push(s_pos[i].first, s_pos[i].second, 0);
    }

    BFS();

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(a[i][j] != 2) cout << 0 << ' ';
            else{
                if(!visited[i][j])
                    cout << -1 << ' ';
                else
                    cout << step[i][j] << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}