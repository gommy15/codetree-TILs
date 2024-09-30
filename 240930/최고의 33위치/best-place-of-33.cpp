#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 20

int n, ans;
bool grid[MAX_N][MAX_N];

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

int FoundCoin(int x, int y) {
    int cnt = 0;
    for(int i=x; i<x+3; i++) {
        for(int j=y; j<y+3; j++) {
            if(!InRange(i, j)) return 0;

            if(grid[i][j]) cnt++;
        }
    }

    return cnt;
}


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            ans = max(ans, FoundCoin(i, j));
        }
    }

    cout << ans;

    return 0;
}