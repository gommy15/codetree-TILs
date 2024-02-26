#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 10
#define MAX_AB 10000

int n;
int a[MAX_N], b[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i]>>b[i];
    }
    
    int ans = 0;
    for(int i=1; i<MAX_AB; i++) {
        int num = i;

        bool success = true;
        for(int j=0; j<n; j++) {
            num *= 2;
            if(a[j] <= num && num <= b[j]) continue;
            else {
                success = false;
                break;
            }
        }

        if(success) {
            ans = i;
            break;
        }
    }

    cout << ans;
    return 0;
}