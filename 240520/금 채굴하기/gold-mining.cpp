// 마름모 내부인지 확인하는 공식을 아는 것이 중요!!!
// 마름모 중앙의 위치를 (a, b), 임의의 위치를 (c, d)라고 했을 때
// |c-a| + |d-b| <= k 이면 해당 위치는 마름모에 포함된다고 볼 수 있음!
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 20

int n, m, ans;
int grid[MAX_N][MAX_N];

int CountGold(int x, int y, int k) {
    int cnt = 0;
    // 범위를 지정하는 것보다 처음부터 반복문을 돌려서 값을 찾는 것이 더 빠르다
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(abs(i-x) + abs(j-y) <= k)
                cnt += grid[i][j];
        }
    }

    return cnt;
}

int Area(int k) {
    return k*k + (k+1)*(k+1);
}

void Simulate() {
    // k는 2*(n-1)까지 커질 수 있음
    for(int k=0; k<=2*(n-1); k++) {
        int max_cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                max_cnt = max(max_cnt, CountGold(i, j, k));
            }
        }

        // 손해보지 않는 선이므로 0이상일 때를 기준으로 한다
        if(max_cnt*m-Area(k) >= 0) {
            ans = max(ans, max_cnt);
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    Simulate();

    cout << ans;
    return 0;
}