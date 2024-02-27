#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define MAX_N 100

int n;
int arr[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    string str;
    cin >> n >> str;
    for(int i=0; i<n; i++) {
        arr[i] = str[i] - '0';
    }

    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i] == 1 || arr[j] == 1) continue;
            arr[i] = 1;
            arr[j] = 1;

            int tmp[MAX_N] = {};
            int cnt = 0;
            for(int k=0; k<n; k++) {
                if(arr[k] == 1) tmp[cnt++] = k;
            }

            int min_dis = n;
            for(int k=0; k<cnt-1; k++) {
                min_dis = min(min_dis, (tmp[k+1]-tmp[k]+1));
            }

            ans = max(ans, min_dis);
        }
    }

    cout << ans;
    return 0;
}