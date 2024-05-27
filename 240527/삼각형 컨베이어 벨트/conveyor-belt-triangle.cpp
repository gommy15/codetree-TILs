#include <iostream>
using namespace std;
#define MAX_N 200

int n, t;
int arr[MAX_N*3];

void Move() {
    int tmp = arr[3*n-1];

    for(int i=3*n-2; i>=0; i--) {
        arr[i+1] = arr[i];
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
        Move();
    }

    for(int i=0; i<3*n; i++) {
        if(i != 0 && i%n == 0) cout << '\n';
        cout << arr[i] << ' ';
    }
    return 0;
}