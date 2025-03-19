#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100

int n, m;
int grid[MAX_N][MAX_N];
int tmp[MAX_N];

bool Check() {
    int cnt = 1;
    int max_c = 0;

    for (int i=1; i<n; i++) {
        if(tmp[i-1] == tmp[i]) cnt += 1;
        else {
            max_c = max(max_c, cnt);
            cnt = 1;
        }
    }

    max_c = max(max_c, cnt);
    if (max_c >= m) return true;
    else return false;
}


int main() {
    cin >> n>>m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            tmp[j] = grid[i][j];
        }

        if (Check()) {
            ans += 1;
        }

        for(int j=0; j<n; j++) {
            tmp[j] = grid[j][i];
        }

        if (Check()) {
            ans += 1;
        }
    }

    cout << ans;

    return 0;
}