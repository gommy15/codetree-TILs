#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 20

int n, ans;
int grid[MAX_N][MAX_N];

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

void Simulate() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(!InRange(i+2, j+2)) continue;

            int cnt = 0;
            for(int k=0; k<3; k++) {
                for(int l=0; l<3; l++) {
                    cnt += grid[i+k][j+l];
                }
            }

            ans = max(ans, cnt);
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    Simulate();

    cout << ans;
    return 0;
}