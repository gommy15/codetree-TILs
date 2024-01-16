#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_R 1000

int n;
int arr[MAX_R];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int max_cnt = INT_MIN;
    int cnt = 0;
    for(int i=0; i<MAX_R; i++) {
        if(i ==0 || arr[i] == arr[i-1]) cnt++;
        else {
            max_cnt = max(max_cnt, cnt);
            cnt = 1;
        }
    }
    cout << max_cnt;

    return 0;
}