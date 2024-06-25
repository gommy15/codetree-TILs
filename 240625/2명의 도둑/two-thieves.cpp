#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 10
#define MAX_M 5

int n, m, c;
int weight[MAX_N][MAX_N];

int a[MAX_M];

int ans;
int max_val;

bool Intersect(int a1, int a2, int b1, int b2) {
    return (a2<b1 || b2<a1);
}

bool Possible(int x1, int y1, int x2, int y2) {
    if(y1+m-1 >=n || y2+m-1>=n) return false;

    if(x1 != x2) return true;

    if(!Intersect(y1, y1+m-1, y2, y2+m-1))
        return false;

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
    for(int i=y; i<y+m; i++) {
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

    for(int a1=0; a1<n; a1++) {
        for(int b1=0; b1<n; b1++) {
            for(int a2=0; a2<n; a2++) {
                for(int b2=0; b2<n; b2++) {
                    if(Possible(a1, b1, a2, b2))
                        ans = max(ans, FindMax(a1, b1)+FindMax(a2, b2));
                }
            }
        }
    }

    cout << ans;
    return 0;
}