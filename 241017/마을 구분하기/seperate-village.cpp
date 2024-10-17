#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 25
#define DIR_NUM 4

int n;
int grid[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
vector<int> village;
int cnt;

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

bool Cango(int x, int y) {
    if(!InRange(x, y)) return false;
    if(visited[x][y] || grid[x][y] == 0) return false;

    return true;
}

void DFS(int x, int y) {
    int dx[DIR_NUM] = {-1, 0, 1, 0};
    int dy[DIR_NUM] = {0, -1, 0, 1};

    for(int d=0; d<DIR_NUM; d++) {
        int nx = x+dx[d];
        int ny = y+dy[d];

        if(Cango(nx, ny)) {
            cnt++;
            visited[nx][ny] = 1;
            DFS(nx, ny);
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
            if(grid[i][j] == 1 && visited[i][j] == false) {
                cnt = 1;
                visited[i][j] = true;
                DFS(i, j);
                village.push_back(cnt);
            }
        }
    }

    sort(village.begin(), village.end());
    cout << village.size() << '\n';

    for(int& v : village) {
        cout << v << '\n';
    }

    return 0;
}