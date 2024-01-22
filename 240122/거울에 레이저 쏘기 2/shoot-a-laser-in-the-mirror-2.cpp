// 각 기호를 만났을 때 어느 방향으로 바뀌는지를 그림을 그려서 생각해보기!!!!

#include <iostream>
using namespace std;
#define MAX_N 1000

int n, k;
char arr[MAX_N][MAX_N];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    cin >> k;
    int x, y, dir;
    if(k <= n) {
        x = 0; y = k-1; dir = 0;
    } else if (k <= 2*n) {
        x = (k-1)%n; y = n-1; dir = 1;
    } else if (k <= 3*n) {
        x = n-1; y = n-(k%n); dir = 2;
    } else {
        x = n-(k%n); y = 0; dir = 3;
    }

    int cnt = 0;
    while(InRange(x, y)) {
        if(arr[x][y] == '/') {
            dir = dir ^ 1;
            x += dx[dir];
            y += dy[dir];
        } else {
            dir = 3-dir;
            x += dx[dir];
            y += dy[dir];
        }
        
        cnt++;
    }

    cout << cnt;

    return 0;
}