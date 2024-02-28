#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_NM 100
#define MAX_A 100

int n, m;
int arr[MAX_NM];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >>n>>m;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    for(int a=1; a<=MAX_A; a++) {
        int b_cnt = 0;
        int b_sum = 0;
        bool possible = true;
        for(int i=0; i<n; i++) {
            if(arr[i] > a) {
                possible = false;
                break;
            }

            if(b_sum + arr[i] > a) {
                b_cnt++;
                b_sum = 0;
            }

            b_sum += arr[i];
        }

        if(possible && b_cnt == m-1) {
            cout << a;
            break;
        }
    }
    return 0;
}