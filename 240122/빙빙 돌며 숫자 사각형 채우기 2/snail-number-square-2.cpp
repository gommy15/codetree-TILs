#include <iostream>
using namespace std;
#define MAX_NM 100

int arr[MAX_NM][MAX_NM];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int n, m;

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;
    int x = 0, y = 0, dir_num = 0;
    arr[x][y] = 1;
    for(int i=1; i<n*m; i++) {
        int nx = x+dx[dir_num], ny = y+dy[dir_num];

        if(InRange(nx, ny) && arr[nx][ny] == 0) {
            arr[nx][ny] = i+1;
            x = nx;
            y = ny;
        }
        else {
            dir_num = (dir_num+1)%4;
            x += dx[dir_num];
            y += dy[dir_num];
            arr[x][y] = i+1;
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}