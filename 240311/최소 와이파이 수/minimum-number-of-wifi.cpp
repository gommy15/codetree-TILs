#include <iostream>
using namespace std;
#define MAX_N 100

int n, m;
int arr[MAX_N+1];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;
    int cnt = 0;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
        if(arr[i] == 1) cnt++;
    }

    if(m == 0) {
        cout << cnt;
        return 0;
    } else if (n == 1 && cnt == 0) {
        cout << cnt;
        return 0;
    }

    int area = 2*m+1;
    cnt = n/area;
    if(n%area != 0 && arr[area+1] != 0) cnt++;

    cout << cnt;
    return 0;
}