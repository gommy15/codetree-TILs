#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 10
#define MAX_M 5


int n, m, c;
int grid[MAX_N][MAX_N];

int a[MAX_M];

int ans, max_val;

bool Overlapped(int y1, int y2, int b1, int b2) {
    return !(y2 < b1 || b2 < y1);
}

bool Possible(int x, int y, int a, int b) {
    if (y+m-1 >=m || b+m-1 >=n) return false;

    if (x != a) return true;

    if (Overlapped(y, y+m-1, b, b+m-1)) return false;

    return true;
}

void FindMaxSum(int idx, int w, int v) {
    if(idx == m) {
        if(w <= c) {
            max_val = max(max_val, v);
        }
        return;
    }

    FindMaxSum(idx+1, w, v);

    FindMaxSum(idx+1, w+a[idx], v+(a[idx]*a[idx]));
}

int FindMax(int x, int y) {

    for(int i=y; i<y+m; i++) {
        a[i-y] = grid[x][i];
    }

    max_val = 0;
    FindMaxSum(0, 0, 0);
    return max_val;
}

int main() {
    cin >> n>>m>>c;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    for(int x=0; x<n; x++) {
        for(int y=0; y<n; y++) {
            for (int a=0; a<n; a++) {
                for(int b=0; b<n; b++) {
                    if(Possible(x, y, a, b)) {
                        ans = max(ans, FindMax(x, y) + FindMax(a, b));
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}