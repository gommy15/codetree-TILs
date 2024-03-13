#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_NM 200

int n, m;
int arr[MAX_NM][MAX_NM];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<m;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }

    // 첫번쨰 종류의 블럭에서 가장 큰 수 구하기
    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            for(int k=0; k<4; k++) {
                int dir_num = k;
                int sum = arr[i][j];

                int nx1 = i+dx[dir_num], ny1 = j+dy[dir_num];
                dir_num = (dir_num+1)%4;
                int nx2 = i+dx[dir_num], ny2 = j+dy[dir_num];
                if(!InRange(nx1, ny1) || !InRange(nx2, ny2)) continue;

                sum = sum+arr[nx1][ny1]+arr[nx2][ny2];
                ans = max(ans, sum);
            }
        }
    }

    // 두번째 종류의 블럭에서 가장 큰 수 구하기
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            for(int k=0; k<2; k++) {
                int dir_num = k;
                int sum = arr[i][j];

                int nx1 = i+dx[dir_num], ny1 = j+dy[dir_num];
                dir_num = (dir_num+2)%4;
                int nx2 = i+dx[dir_num], ny2 = j+dy[dir_num];
                if(!InRange(nx1, ny1) || !InRange(nx2, ny2)) continue;

                sum = sum+arr[nx1][ny1]+arr[nx2][ny2];
                ans = max(ans, sum);
            }
        }
    }

    cout << ans;
    return 0;
}