#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_NUM 101

int t, a, b;
int s[MAX_NUM], n[MAX_NUM];
int cnt_s = 0, cnt_n = 0;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> t>>a>>b;

    char ch;
    int lo;
    for(int i=0; i<t; i++) {
        cin >> ch>>lo;
        if(ch == 'S') s[cnt_s++] = lo;
        else n[cnt_n++] = lo;
    }

    int ans = 0;

    for(int i=a; i<=b; i++) {
        int d1 = INT_MAX;
        int d2 = INT_MAX;

        for(int j=0; j<cnt_s; j++) {
            d1 = min(d1, abs(s[j]-i));
        }

        for(int j=0; j<cnt_n; j++) {
            d2 = min(d2, abs(n[j]-i));
        }

        if(d1 <= d2) ans++;
    }

    cout << ans;
    return 0;
}