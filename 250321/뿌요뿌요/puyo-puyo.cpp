#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100
#define DIR_NUM 4

int n;
int grid[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

int ans_b, ans_size, block_size;

bool CanGo(int x, int y, int num) {
    return 0<=x && x<n && 0<=y && y<n && grid[x][y] == num && !visited[x][y];
}

void DFS(int x, int y, int num) {
    int dx[DIR_NUM] = {-1, 0, 1, 0};
    int dy[DIR_NUM] = {0, 1, 0, -1};

    for(int d=0; d<DIR_NUM; d++) {
        int nx = x+dx[d], ny = y+dy[d];

        if(CanGo(nx, ny, num)) {
            visited[nx][ny] = true;
            block_size++;
            DFS(nx, ny, num);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(!visited[i][j]) {
                visited[i][j] = true;
                block_size = 1;
                DFS(i, j, grid[i][j]);

                ans_size = max(ans_size, block_size);
                if(block_size >= 4) ans_b++;
            }
        }
    }

    cout << ans_b << ' ' << ans_size;
    return 0;
}