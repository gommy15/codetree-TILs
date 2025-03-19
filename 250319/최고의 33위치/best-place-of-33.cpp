#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 20
#define INLINE 3

int n;
int grid[MAX_N][MAX_N];

bool InRange(int x, int y){
    return 0<=x && x<n && 0<=y && y<n;
}

int Calc(int x, int y) {
    int cnt = 0;

    for(int i=0; i<INLINE; i++) {
        for(int j=0; j<INLINE; j++) {
            if (InRange(x+i, y+j)) {
                cnt += grid[x+i][y+j];
            }
        }
    }

    return cnt;

}


int main() {
    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            ans = max(ans, Calc(i, j));
        }
    }

    cout << ans;

    
    return 0;
}