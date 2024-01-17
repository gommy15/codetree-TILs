#include <iostream>
using namespace std;
#define MAX_AR 1000000

int n, m;
int arr_A[MAX_AR+1], arr_B[MAX_AR+1];
char d;
int t;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;

    int d_num, now = 0, idx = 0;
    for(int i=0; i<n; i++) {
        cin >>d>>t;

        if(d == 'L') d_num = -1;
        else d_num = 1;
        for(int i=idx; i<=idx+t; i++) {
            arr_A[i] = now;
            now += d_num;
            // cout << arr_A[i] << ' ';
        }
        idx += t;
    }

    // cout << '\n';
    int min_idx = idx;

    now = 0, idx = 0;
    for(int i=0; i<m; i++) {
        cin >>d>>t;

        if(d == 'L') d_num = -1;
        else d_num = 1;
        for(int i=idx; i<=idx+t; i++) {
            arr_B[i] = now;
            now += d_num;
            // cout << arr_B[i] << ' ';
        }
        idx += t;
    }

    // cout << '\n';
    min_idx = min(min_idx, idx);

    int meet_time = -1;
    for(int i=1; i<=min_idx; i++) {
        if(arr_A[i] == arr_B[i]) {
            meet_time = i;
            break;
        }
    }

    cout << meet_time;
    return 0;
}