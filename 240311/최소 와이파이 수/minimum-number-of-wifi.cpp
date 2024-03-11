#include <iostream>
using namespace std;
#define MAX_N 100

int n, m;
int arr[MAX_N+1];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    int area = 2*m+1;
    int cnt = n/area;
    if(n%area != 0) cnt++;

    cout << cnt;
    return 0;
}