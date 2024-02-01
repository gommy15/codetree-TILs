#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N   100

int n, k;
int arr[MAX_N+1];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>k;
    int idx, num;
    for(int i=0; i<n; i++) {
        cin >> num>>idx;
        arr[idx] += num;
    }

    int max_sum = 0;

    for(int i=0; i<=MAX_N; i++) {
        int sum = 0;
        for(int j=i-k; j<=i+k; j++) {
            if(j >= 0 && j <= MAX_N) sum += arr[j];
        }
        max_sum = max(max_sum, sum);
    }

    cout << max_sum;
    return 0;
}