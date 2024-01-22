#include <iostream>
using namespace std;
#define MAX_N 100

int n;
int arr[MAX_N][MAX_N];
int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    int x = n-1, y = n-1, dir_num = 0;
    arr[x][y] = n*n;

    for(int i=n*n; i>1; i--) {
        while(true) {
            int nx = x+dx[dir_num], ny = y+dy[dir_num];

            if(InRange(nx, ny) && arr[nx][ny] == 0) {
                x = nx;
                y = ny;
                arr[x][y] = i-1;
                break;
            } else {
                dir_num = (dir_num+1)%4;
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}