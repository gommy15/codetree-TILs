#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 20

int n;
int arr[MAX_N][MAX_N];
int dx[4] = {-1, -1, 1, 1}, dy[4] = {1, -1, -1, 1};

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

// 1과 3이 커질때
int RecSumFist(int x, int y, int k) {
    int sum = 0;
    for(int i=0; i<4; i++) {
        int dir_num = i;
        if(dir_num%2 == 0) {
            for(int j=0; j<k; j++) {
                int nx = x+dx[dir_num], ny=y+dy[dir_num];

                if(!InRange(nx, ny)) return 0;
                sum += arr[nx][ny];
                x = nx;
                y = ny;
            }
        } else {
            int nx = x+dx[dir_num], ny=y+dy[dir_num];

            if(!InRange(nx, ny)) return 0;
            sum += arr[nx][ny];
            x = nx;
            y = ny;
        }
    }

    return sum;
}

// 2과 4가 커질때
int RecSumSecon(int x, int y, int k) {
    int sum = 0;
    for(int i=0; i<4; i++) {
        int dir_num = i;
        if(dir_num%2 == 1) {
            for(int j=0; j<k; j++) {
                int nx = x+dx[dir_num], ny=y+dy[dir_num];

                if(!InRange(nx, ny)) return 0;
                sum += arr[nx][ny];
                x = nx;
                y = ny;
            }
        } else {
            int nx = x+dx[dir_num], ny=y+dy[dir_num];

            if(!InRange(nx, ny)) return 0;
            sum += arr[nx][ny];
            x = nx;
            y = ny;
        }
    }

    return sum;
}

// 1, 2, 3, 4가 동시에 커질 때
int RecSumThird(int x, int y, int k) {
    int sum = 0;
    for(int i=0; i<4; i++) {
        int dir_num = i;
        for(int j=0; j<k; j++) {
            // if(k == 2) {
            //     cout << arr[x][y] << ' ';
            // }
            int nx = x+dx[dir_num], ny=y+dy[dir_num];

            if(!InRange(nx, ny)) return 0;
            sum += arr[nx][ny];
            x = nx;
            y = ny;
        }
    }

    // cout << sum << '\n';
    return sum;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    int max_sum = 0;
    for(int i=n-1; i>1; i--) {
        for(int j=1; j<n-1; j++) {
            int k = 1;
            while(k < n) {
                max_sum = max(max_sum, RecSumFist(i, j, k));
                // cout << k << ' ' << max_sum << ' ';
                max_sum = max(max_sum, RecSumSecon(i, j, k));
                // cout << max_sum << ' ';
                max_sum = max(max_sum, RecSumThird(i, j, k));
                // cout << max_sum << '\n';
                k++;
            }
        }
    }

    cout << max_sum;

    return 0;
}