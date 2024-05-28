#include <iostream>
using namespace std;
#define MAX_N 100

int n, ans;
int arr[MAX_N], tmp[MAX_N];

void Simulate(int s, int e) {
    for(int i=0; i<n; i++) {
        tmp[i] = 0;
    }

    int cnt = 0;
    for(int i=0; i<n; i++) {
        if(s<=i && i<=e)
            continue;
        
        tmp[cnt++] = arr[i];
    }

    ans = 0;
    for(int i=0; i<n; i++) {
        arr[i] = tmp[i];
        if(tmp[i] != 0) ans++;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    for(int i=0; i<2; i++) {
        int s, e;
        cin >> s>>e;
        Simulate(s-1, e-1);
    }

    cout << ans << '\n';
    for(int i=0; i<n; i++) {
        if(arr[i] == 0) {
            break;
        }

        cout << arr[i] << '\n';
    }
    return 0;
}