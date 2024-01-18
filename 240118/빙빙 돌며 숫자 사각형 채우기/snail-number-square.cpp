#include <iostream>
using namespace std;
#define MAX_NM 100

int arr[MAX_NM][MAX_NM];
int n, m;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<m;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >>n>>m;
    int dir_num = 0, num = 1;
    int x = 0, y = 0;
    
    arr[x][y] = 1;
    for(int i=2; i<=n*m; i++) {
        int nx = x+dx[dir_num], ny = y+dy[dir_num];

        if(!InRange(nx, ny) || arr[nx][ny] != 0) {
            dir_num = (dir_num+1)%4;
        }

        x += dx[dir_num];
        y += dy[dir_num];
        arr[x][y] = i;
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}