#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100

int n, r, c;
int arr[MAX_N][MAX_N];

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

void Simulate(int x, int y) {
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

    while(true) {
        bool exist = false;
        int max_num = arr[x][y];
        cout << max_num << ' ';
        for(int dir_num = 0; dir_num<4; dir_num++) {
            int nx = x+dx[dir_num], ny = y+dy[dir_num];

            if(!InRange(nx, ny)) continue;

            if(max_num < arr[nx][ny]) {
                max_num = arr[nx][ny];
                x = nx;
                y = ny;
                exist = true;
                break;
            }
        }

        if(!exist) return;

    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>r>>c;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    Simulate(r-1, c-1);
    return 0;
}