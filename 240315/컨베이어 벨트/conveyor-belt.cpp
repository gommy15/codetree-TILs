#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 200

int n, t;
int arr[MAX_N*2];

void ChangeState() {
    int tmp = arr[n*2-1];
    for(int i=2*n-1; i>0; i--) {
        arr[i] = arr[i-1];
    }
}

int main() {
    cin >> n>>t;
    for(int i=0; i<2*n; i++) {
        cin >> arr[i];
    }

    while(t--) {
        ChangeState();
    }

    for(int i=0; i<2*n; i++) {
        if(i == n) cout << '\n';
        cout << arr[i] << ' ';
    }

    return 0;
}