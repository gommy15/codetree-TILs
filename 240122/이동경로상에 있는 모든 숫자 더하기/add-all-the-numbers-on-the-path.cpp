#include <iostream>
using namespace std;
#define MAX_N 99
#define MAX_T 100000

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int n, t;
char direc[MAX_T];
int arr[MAX_N][MAX_N];

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>t;
    for(int i=0; i<t; i++) {
        cin >> direc[i];
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    int x = n/2, y = n/2, dir_num = 0;
    int sum = arr[x][y];

    for(int i=0; i<t; i++) {
        if(direc[i] == 'L') dir_num = (dir_num-1+4)%4;
        else if (direc[i] == 'R') dir_num = (dir_num+1)%4;
        else {
            int nx = x+dx[dir_num], ny = y+dy[dir_num];

            if(InRange(nx, ny)) {
                x = nx; y = ny;
                sum += arr[x][y];
            }
        }
    }

    cout << sum;
    return 0;
}