#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_T  100

int t, a, b;
int s[MAX_T], n[MAX_T];
int s_cnt = 0, n_cnt = 0;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> t>>a>>b;
    char alpa;
    int idx;
    for(int i=0; i<t; i++) {
        cin >>alpa>>idx;
        if(alpa == 'S') s[s_cnt++] = idx;
        else n[n_cnt++] = idx;
    }

    int cnt = 0;
    for(int i=a; i<=b; i++) {
        int d1=INT_MAX, d2=INT_MAX;

        // d1 찾기
        for(int j=0; j<s_cnt; j++) {
            d1 = min(d1, abs(s[j]-i));
        }

        // d2 찾기
        for(int j=0; j<n_cnt; j++) {
            d2 = min(d2, abs(n[j]-i));
        }

        if(d1 <= d2) cnt++;
    }

    cout << cnt;
    return 0;
}