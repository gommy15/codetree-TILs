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
    int max_num = 0;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        max_num = max(max_num, arr[i]);
    }

    int max_cnt = INT_MIN;

    for(int k=1; k<max_num; k++) {
        int cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if((k-arr[i]) == (arr[j]-k)) cnt++;
            }
        }

        max_cnt = max(max_cnt, cnt);
    }


    cout << max_cnt;
    return 0;
}