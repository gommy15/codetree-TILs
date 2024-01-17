#include <iostream>
using namespace std;
#define MAX_AR 1000

int n, m;
int arr_A[MAX_AR], arr_B[MAX_AR];
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
        for(int i=idx; i<idx+t; i++) {
            arr_A[i] = now;
            now += d_num;
        }
        idx += t;
    }

    now = 0, idx = 0;
    for(int i=0; i<m; i++) {
        cin >>d>>t;

        if(d == 'L') d_num = -1;
        else d_num = 1;
        for(int i=idx; i<idx+t; i++) {
            arr_B[i] = now;
            now += d_num;
        }
        idx += t;
    }

    int meet_time = -1;
    for(int i=1; i<MAX_AR; i++) {
        if(arr_A[i] == arr_B[i]) {
            meet_time = i;
            break;
        }
    }

    cout << meet_time;
    return 0;
}