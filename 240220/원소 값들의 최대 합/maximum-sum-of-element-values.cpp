#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 100

int n, m;
int arr[MAX_N+1];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    int max_sum = INT_MIN;

    // 시작 위치 설정
    for(int i=1; i<=n; i++) {
        int sum = 0;
        int idx = i;

        for(int j=0; j<m; j++) {
            sum += arr[idx];
            idx = arr[idx];
        }

        max_sum = max(max_sum, sum);
    }

    cout << max_sum;
    return 0;
}