#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define MAX_N 20

int n;
string arr_S;
int arr[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>arr_S;
    for(int i=0; i<n; i++) {
        arr[i] = arr_S[i] - '0';
    }

    int max_dis = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] == 1) continue;
        arr[i] = 1;
        int idx_tmp[MAX_N] = {};
        int cnt = 0;
        for(int j=0; j<n; j++) {
            if(arr[j] == 1) idx_tmp[cnt++] = j;
        }
        
        int min_dis = MAX_N;
        for(int j=0; j<cnt-1; j++) {
            min_dis = min(min_dis, (idx_tmp[j+1] - idx_tmp[j]));
        }

        max_dis = max(max_dis, min_dis);
        arr[i] = 0;
    }


    cout << max_dis;
    return 0;
}