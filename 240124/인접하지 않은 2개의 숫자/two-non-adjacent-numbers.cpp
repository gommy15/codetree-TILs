#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 100

int n;
int arr[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int max_sum = INT_MIN;
    for(int i=0; i<n; i++) {
        int sum = 0;
        for(int j=i; j<n; j++) {
            if(i == j || i+1 == j) continue;
            
            max_sum = max(max_sum, arr[i] + arr[j]);
            // cout << "sum : " << arr[i] << ' ' << arr[j] << '\n';
        }
    }

    cout << max_sum;
    return 0;
}