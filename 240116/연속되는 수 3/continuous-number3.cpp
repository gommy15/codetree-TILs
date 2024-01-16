#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N   1000

int n;
int arr[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    int num;
    for(int i=0; i<n; i++) {
        cin >> num;
        if(num > 0) arr[i] = 1;
        else arr[i] = -1;
    }

    int cnt = 0, max_cnt = INT_MIN;
    for(int i=0; i<n; i++) {
        if(i==0|| arr[i-1] == arr[i]) cnt++;
        else {
            max_cnt = max(max_cnt, cnt);
            cnt = 1;
        }
    }

    cout << max_cnt;
    return 0;
}