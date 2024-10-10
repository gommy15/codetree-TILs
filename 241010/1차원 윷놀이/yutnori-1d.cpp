#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_N 12
#define MAX_K 4

int n, m, k;
int moving[MAX_N], point[MAX_K+1];
int ans=0;

int Calc() {
    int cnt = 0;
    for(int i=1; i<=k; i++) {
        if(point[i] >= m) {
            cnt++;
        }
    }

    return cnt;
}

void Simulate(int cnt) {
    ans = max(ans, Calc());

    if(cnt == n) return;

    for(int i=1; i<=k; i++) {
        if(point[i] >= m) continue;

        point[i] += moving[cnt];
        Simulate(cnt+1);
        point[i] -= moving[cnt];
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m>>k;

    for(int i=0; i<n; i++) {
        cin >> moving[i];
    }

    for(int i=1; i<=k; i++) {
        point[i] = 1;
    }

    Simulate(0);

    cout << ans;
    return 0;
}