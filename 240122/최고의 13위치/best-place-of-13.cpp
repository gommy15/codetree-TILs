#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 20

int arr[MAX_N][MAX_N];
int n;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    int max_cnt = INT_MIN;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n-2; j++) {
            max_cnt = max(max_cnt, arr[i][j] + arr[i][j+1] + arr[i][j+2]);
        }
    }

    cout << max_cnt;
    return 0;
}