#include <iostream>
using namespace std;
#define MAX_NM 100

int arr[MAX_NM][MAX_NM];
int n, m;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;
    int x=0, y=0, dir_num = 0;
    arr[x][y] = 1;

    for(int i=1; i<n*m; i++) {
        while(true) {
            int nx = x+dx[dir_num], ny = y+dy[dir_num];

            if(InRange(nx, ny) && arr[nx][ny] == 0) {
                x = nx; y = ny;
                arr[x][y] = i+1;
                break;
            } else {
                dir_num = (dir_num+1)%4;
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            char ans = ((arr[i][j]-1)%26) + 'A';

            cout << ans<< ' ';
        }
        cout << '\n';
    }
    return 0;
}