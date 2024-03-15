#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_NM 20

int n, m;
int grid[MAX_NM][MAX_NM];

bool CheckRect(int x1, int y1, int x2, int y2) {
    for(int i=x1; i<=x2; i++) {
        for(int j=y1; j<=y2; j++) {
            if(grid[i][j] <= 0) return false;
        }
    }
    return true;
}

int CntRect(int x1, int y1, int x2, int y2) {
    return (x2-x1+1) * (y2-y1+1);
}

int FindRec() {
    int ans = -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            for(int k=i; k<n; k++) {
                for(int l=j; l<m; l++) {
                    if(CheckRect(i, j, k, l)) {
                        // cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << CheckRect(i, j, k, l) << '\n';
                        ans = max(ans, CntRect(i, j, k, l));
                    }
                }
            }
        }
    }
    return ans;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = FindRec();

    cout << ans;
    return 0;
}