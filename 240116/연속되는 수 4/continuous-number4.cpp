#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 1000

int n;
int arr[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int cnt = 0, max_cnt = INT_MIN;
    for(int i=0; i<n; i++) {
        if(i==0||arr[i-1] < arr[i]) cnt++;
        else {
            max_cnt = max(max_cnt, cnt);
            cnt=1;
        }
    }
    max_cnt = max(max_cnt, cnt);
    cout << max_cnt;
    return 0;
}