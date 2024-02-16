#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 100
#define MAX_NUM 100

int n;
int nums[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    int max_cnt = 0;
    for(int k=1; k<=MAX_NUM; k++) {
        int cnt = 0;

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                // if((nums[i]+nums[j]) == (2*k)) cnt++;
                if((nums[j]-k) == (k-nums[i])) cnt++;
            }
        }
        max_cnt = max(max_cnt, cnt);
    }

    cout << max_cnt;
    return 0;
}