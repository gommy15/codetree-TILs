#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100

int n;
int arr[MAX_N], tmp[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        tmp[i] = arr[i];
    }

    sort(tmp, tmp+n);

    if(tmp[0] == tmp[1] || tmp[1] == tmp[2]) {
        cout << -1;
        return 0;
    }

    for(int i=0; i<n; i++) {
        if(arr[i] == tmp[1]) {
            cout << i+1;
            break;
        }
    }
    return 0;
}