#include <iostream>
using namespace std;
#define MAX_N 1000
#define MOD 10007

int n;
int arr[MAX_N+1];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    
    for(int i=3; i<=n; i++) {
        arr[i] = (arr[i-1] + arr[i-2])%MOD;
    }

    cout << arr[n];
    return 0;
}