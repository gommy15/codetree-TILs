#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1000

int n, k;
int arr[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>k;

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int max_num = *max_element(arr, arr+n);
    int min_num = *min_element(arr, arr+n);

    int max_cnt = 0;
    for(int a=min_num; a<=max_num; a++) {
        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(a <= arr[i] && arr[i] <= a+k) cnt++;
        }

        max_cnt = max(max_cnt, cnt);
    }

    cout << max_cnt;
    return 0;
}