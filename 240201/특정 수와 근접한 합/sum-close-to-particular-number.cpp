#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 100

int s, n;
int arr[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>s;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int min_diff = INT_MAX;
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            int sum = 0;
            for(int k=0; k<n; k++) {
                if(k == i || k == j) continue;
                sum += arr[k];
            }
            int diff = abs(sum - s);
            min_diff = min(min_diff, diff);
        }
    }

    cout << min_diff;
    return 0;
}