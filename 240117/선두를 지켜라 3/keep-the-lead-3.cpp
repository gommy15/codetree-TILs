#include <iostream>
using namespace std;
#define MAX_AR 1000000

int n, m, v, t;
int arr_a[MAX_AR+1], arr_b[MAX_AR+1];
int leader[MAX_AR+1];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;

    int now = 1;
    for(int i=0; i<n; i++) {
        cin >>v>>t;
        while(t--) {
            arr_a[now] = arr_a[now-1] + v;
            now++;
            // cout << t << '\n';
        }
    }

    now = 1;
    // cout << now;
    for(int i=0; i<m; i++) {
        cin >>v>>t;

        while(t--) {
            arr_b[now] = arr_b[now-1] + v;
            now++;
        }
    }

    // cout << now;
    int cnt = 0;
    for(int i=1; i<now; i++) {
        if(arr_a[i] > arr_b[i]) leader[i] = 1;
        else if (arr_a[i] < arr_b[i]) leader[i] = 2;
        else leader[i] = 3;

        // cout << leader[i] << ' ';
    }
    cout << '\n';

    for(int i=1; i<now; i++) {
        if(leader[i] != leader[i+1]) cnt++;
    }

    cout << cnt;

    return 0;
}