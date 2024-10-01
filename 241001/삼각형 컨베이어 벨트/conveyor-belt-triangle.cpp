#include <iostream>
using namespace std;
#define MAX_N 200

int n, t;
int arr[MAX_N*3];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>t;
    for(int i=0; i<n*3; i++) {
        cin >> arr[i];
    }

    while(t--) {
        int tmp = arr[n*3-1];

        for(int i=n*3-1; i>=0; i--) {
            arr[i] = arr[i-1];
        }

        arr[0] = tmp;
    }

    for(int i=0; i<n*3; i++) {
        cout << arr[i] << ' ';

        if((i+1)%n == 0) cout << '\n';
    }
    return 0;
}