#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
#define MAX_N 1003

int n;
int arr[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int min_sum = INT_MAX;
    for(int i=0; i<n; i++) {
        
        // 두번째 방법
        int sum = 0;
        for(int j=0; j<n; j++) {
            int dis = (j -i + n)%n;
            sum += dis * arr[j];
        }


        // 첫번째 방법
        // int dis = 0;
        // int sum = 0;
        // for(int j=0; j<n; j++) {
        //     int idx = i+j;
        //     if(idx >= n) idx -= n;
        //     sum += (dis*arr[idx]);
        //     dis++;
        // }
        min_sum = min(min_sum, sum);
    }

    cout << min_sum;
    return 0;
}