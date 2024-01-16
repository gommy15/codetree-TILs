#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n, t;
int arr[1000];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>t;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int cnt=0, max_cnt = INT_MIN;
    for(int i=0; i<n; i++) {
        if(arr[i] > t) cnt++;
        else {
            max_cnt = max(max_cnt, cnt);
            cnt = 0;
        }
    }

    max_cnt = max(max_cnt, cnt);
    cout << max_cnt;
    return 0;
}