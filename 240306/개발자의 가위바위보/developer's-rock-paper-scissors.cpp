#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100

int n;
int f_dev[MAX_N], s_dev[MAX_N];

int FindWin(int rock, int siger, int paper) {
    int cnt = 0;

    for(int i=0; i<n; i++) {
        if(f_dev[i] == rock && s_dev[i] == siger) cnt++;
        else if (f_dev[i] == siger && s_dev[i] == paper) cnt++;
        else if (f_dev[i] == paper && s_dev[i] == rock) cnt++;
    }

    return cnt;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> f_dev[i]>>s_dev[i];
    }

    int max_win = 0;
    for(int i=1; i<=3; i++) {
        for(int j=1; j<=3; j++) {
            for(int k=1; k<=3; k++) {
                if(i==j || j==k || k==i) continue;
                max_win = max(max_win, FindWin(i, j, k));
            }
        }
    }

    cout << max_win;
    return 0;
}