#include <iostream>
using namespace std;
#define MAX_AR 1000000

int n, m, v, t;
int now_A[MAX_AR+1], now_B[MAX_AR+1];
// int checked[MAX_AR+1];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;

    int now = 1;
    for(int i=0; i<n; i++) {
        cin >> v>>t;

        while(t--) {
            now_A[now] = now_A[now-1] + v;
            now++;
        }
    }

    now = 1;
    for(int i=0; i<m; i++) {
        cin >> v>>t;

        while(t--) {
            now_B[now] = now_B[now-1] + v;
            now++;
        }
    }

    int leader = 0, cnt=0;
    for(int i=1; i<=now; i++) {
        if(now_A[i] > now_B[i]) {
            if(leader == 2) cnt++;

            leader = 1;

            // checked[i] = 1;
            // leader = 1;
        } else if (now_A[i] < now_B[i]) {
            if(leader == 1) cnt++;

            leader = 2;

            // checked[i] = 2;
            // leader = 2;
        } 
        // else {
        //     checked[i] = leader; 
        // }
    }

    // int cnt = 0;
    // for(int i=1; i<now; i++) {
    //     if(checked[i] != checked[i+1]) cnt++;
    // }

    cout << cnt;
    return 0;
}