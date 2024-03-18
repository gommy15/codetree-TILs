#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 200

int n, t;
int arr[MAX_N*3];

void ChangeNum() {
    int tmp = arr[3*n-1];
    for(int i=3*n-1; i>0; i--) {
        arr[i] = arr[i-1];
    }
    arr[0] = tmp;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>t;
    for(int i=0; i<3*n; i++) {
        cin >> arr[i];
    }

    while(t--) {
        ChangeNum();
    }

    for(int i=0; i<3*n; i++) {
        if(i != 0 && i%n == 0) cout << '\n';
        cout << arr[i] << ' ';
    }

    return 0;
}