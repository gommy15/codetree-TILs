#include <iostream>
using namespace std;
#define MAX_N 1000
#define MOD 1000000007

int n;
int arr[MAX_N+1];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    arr[0] = 1;
    arr[1] = 2;
    
    for(int i=2; i<=n; i++) {
        arr[i] = (arr[i-1]*2 + arr[i-2]*3)%MOD;
        for(int j=i-3; j>=0; j--) {
            arr[i] = (arr[i] + arr[j]*2)%MOD;
        }
    }

    cout << arr[n];

    return 0;
}