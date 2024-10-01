#include <iostream>
using namespace std;
#define MAX_N 200

int n, t;
int arr[MAX_N*2];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>t;

    for(int i=0; i<n*2; i++) {
        cin >> arr[i];
    }

    while(t--) {
        int tmp = arr[n*2-1];

        for(int i=n*2-1; i>=0; i--) {
            arr[i] = arr[i-1];
        }

        arr[0] = tmp;
    }

    for(int i=0; i<n*2; i++) {
        if(i!=0 && i%n == 0) cout << '\n';
        cout << arr[i] << ' ';
    }
    return 0;
}