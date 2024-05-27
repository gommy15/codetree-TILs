#include <iostream>
using namespace std;
#define MAX_N 200

int n, t;
int arr[MAX_N*2];

void Simulate() {
    int tmp = arr[2*n-1];

    for(int i=2*n-2; i>=0; i--) {
        arr[i+1] = arr[i];
    }

    arr[0] = tmp;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>t;
    for(int i=0; i<n*2; i++) {
        cin >> arr[i];
    }

    while(t--) {
        Simulate();
    }
    
    for(int i=0; i<n*2; i++) {
        if(i == n) cout << '\n';

        cout << arr[i] << ' ';
    }
    return 0;
}