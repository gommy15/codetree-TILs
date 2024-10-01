#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_NM 100

int n, m;
int grid[MAX_NM][MAX_NM];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;

    for(int i=0; i<n; i++) {
        int cnt = 1;
        int max_cnt = 0;
        for(int j=1; j<n; j++) {
            if(grid[i][j-1] == grid[i][j]) {
                cnt++;
                max_cnt = max(max_cnt, cnt);
            } else {
                cnt = 1;
            }
        }

        if (max_cnt >= m) ans++;
    }

    for(int i=0; i<n; i++) {
        int cnt = 1;
        int max_cnt = 0;
        for(int j=1; j<n; j++) {
            if(grid[j-1][i] == grid[j][i]) {
                cnt++;
                max_cnt = max(max_cnt, cnt);
            } else {
                cnt = 1;
            }
        }

        if (max_cnt >= m) ans++;
    }

    cout << ans;
    return 0;
}