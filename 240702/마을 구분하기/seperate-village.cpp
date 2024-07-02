#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 25
#define DIR_NUM 4

int n, cnt;
int grid[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
vector<int> people;

int dx[DIR_NUM] = {-1, 1, 0, 0}, dy[DIR_NUM] = {0, 0, -1, 1};

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

bool CanGo(int x, int y) {
    if(!InRange(x, y)) return false;
    if(visited[x][y]) return false;
    if(grid[x][y] == 0) return false;

    return true;
}

void DFS(int x, int y) {
    for(int i=0; i<DIR_NUM; i++) {
        int nx = x+dx[i], ny = y+dy[i];

        if(CanGo(nx, ny)) {
            visited[nx][ny] = 1;
            cnt++;
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
            if(grid[i][j] == 1 && visited[i][j] == 0) {
                visited[i][j] = 1;
                cnt = 1;
                DFS(i, j);

                people.push_back(cnt);
            }
        }
    }
    
    sort(people.begin(), people.end());

    cout << (int) people.size() << '\n';
    for(int i=0; i<people.size(); i++) {
        cout << people[i] << '\n';
    }

    return 0;
}