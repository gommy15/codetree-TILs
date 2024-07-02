#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 100
#define DIR_NUM 4

int n;
int grid[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

int cnt;
vector<int> bomb;

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

bool CanGo(int x, int y, int num) {
    if(!InRange(x, y)) return false;
    if(visited[x][y]) return false;
    if(grid[x][y] != num) return false;

    return true;
}

void DFS(int x, int y, int num) {
    int dx[DIR_NUM] = {-1, 1, 0, 0};
    int dy[DIR_NUM] = {0, 0, -1, 1};

    for(int d=0; d<DIR_NUM; d++) {
        int nx = x+dx[d], ny = y+dy[d];

        if(CanGo(nx, ny, num)) {
            visited[nx][ny] = 1;
            cnt++;
            DFS(nx, ny, num);
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

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cnt = 0;
            if(visited[i][j] == 0) {
                visited[i][j] = 1;
                cnt++;
                DFS(i, j, grid[i][j]);
            }

            bomb.push_back(cnt);
        }
    }

    sort(bomb.begin(), bomb.end());

    int ans = 0;

    for(int i=0; i<(int) bomb.size(); i++) {
        if(bomb[i] >= 4) ans++;
    }

    cout << ans << ' ' << bomb[(int)bomb.size()-1];
    return 0;
}