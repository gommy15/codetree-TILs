#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 10
#define MAX_M 5

int n, m, c;
int weight[MAX_N][MAX_N];
int a[MAX_M];

int ans, max_val;

bool Intersect(int a1, int a2, int b1, int b2) {
    return !(a2 < b1 || b2 < a1);
}

bool Possible(int a1, int a2, int b1, int b2) {
    if(a2+m-1 >=n || b2+m-1 >= n) return false;

    if(a1 != b1) return true;

    if(Intersect(a2, a2+m-1, b2, b2+m-1)) return false;

    return true;
}

void FindMaxSum(int curr_idx, int curr_weight, int curr_val) {
    if(curr_idx == m) {
        if(curr_weight <= c)
            max_val = max(max_val, curr_val);
        return;
    }

    FindMaxSum(curr_idx+1, curr_weight, curr_val);

    FindMaxSum(curr_idx+1, curr_weight+a[curr_idx], curr_val+a[curr_idx]*a[curr_idx]);
}

int FindMax(int x, int y) {
    for(int i=y; i<=y+m-1; i++) {
        a[i-y] = weight[x][i];
    }

    max_val = 0;
    FindMaxSum(0, 0, 0);
    return max_val;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m>>c;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> weight[i][j];
        }
    }

    for(int x=0; x<n; x++) {
        for(int y=0; y<n; y++) {
            for(int nx=0; nx<n; nx++) {
                for(int ny=0; ny<n; ny++) {
                    if(Possible(x, y, nx, ny)){
                        ans = max(ans, FindMax(x, y)+FindMax(nx, ny));
                    }
                }
            }
        }
    }

    cout << ans;
    return 0;
}