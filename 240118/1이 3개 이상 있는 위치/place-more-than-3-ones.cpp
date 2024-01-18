#include <iostream>
using namespace std;
#define MAX_N 100

int arr[MAX_N][MAX_N];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int n;

bool InRange(int x, int y) {
    return 0 <= x && x <n && 0 <= y && y < n;
}

int Checked(int x, int y) {
    int cnt = 0;
    for(int i=0; i<4; i++) {
        int nx = x+dx[i], ny = y+dy[i];
        if(InRange(nx, ny) && arr[nx][ny] == 1) cnt++;
        // cout << cnt << ' ';
    }

    return cnt;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
            // cout << arr[i][j] << ' ';
        }
        // cout << '\n';
    }

    int cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(Checked(i, j) >= 3) cnt++;
            // cout << Checked(i, j) << '\n';
        }
    }

    cout << cnt;
    return 0;
}