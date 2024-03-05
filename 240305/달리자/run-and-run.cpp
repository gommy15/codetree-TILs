#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100

int n;
int a[MAX_N], b[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    for(int i=0; i<n; i++) {
        cin >> b[i];
    }

    int ans = 0;
    // 최소 얼마만큼 거리를 달려야 하는지 계산
    for(int i=0; i<n; i++) {
        if(a[i] > b[i]) {
            // 최소 a[i]-b[i] 명의 사람들이 오른쪽으로 달려야 함
            int num = a[i] - b[i];
            a[i] -= num;
            a[i+1] += num;
            ans += num;
        }
    }

    cout << ans;
    
    return 0;
}