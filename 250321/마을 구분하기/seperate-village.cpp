#include <bits/stdc++.h>
using namespace std;

#define MAX_N 25
#define DIR_NUM 4

int n;
int grid[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

vector<int> people;
int cnt = 0;

bool CanGo(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n && grid[x][y] && !visited[x][y];
}

void DFS(int x, int y) {
    int dx[DIR_NUM] = {-1, 0, 1, 0}, dy[DIR_NUM] = {0, 1, 0, -1};

    for(int d=0; d<DIR_NUM; d++) {
        int nx = x+dx[d], ny = y+dy[d];

        if(CanGo(nx, ny)) {
            visited[nx][ny] = true;
            cnt++;
            DFS(nx, ny);
        }
    }
}

int main() {
    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(grid[i][j] && !visited[i][j]) {
                visited[i][j] = true;
                cnt = 1;
                DFS(i, j);

                people.push_back(cnt);
            }
        }
    }

    cout << (int)people.size() << '\n';
    sort(people.begin(), people.end());
    for(const auto& p : people) {
        cout << p << '\n';
    }
    return 0;
}