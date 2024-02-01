#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100

int n, k;
int arr[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>k;

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int max_sum = 0;
    for(int i=0; i<n-k+1; i++) {
        int sum = 0;
        for(int j=i; j<i+k; j++) {
            sum += arr[j];
        }
        max_sum = max(max_sum, sum);
    }

    cout << max_sum;
    return 0;
}