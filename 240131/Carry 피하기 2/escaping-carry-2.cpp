#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N   20

int n;
int arr[MAX_N];

bool FindCarry(int a, int b, int c) {
    int sum = a+b+c;
    int na, nb, nc;
    while(sum) {
        na = a%10;
        nb = b%10;
        nc = c%10;

        if(na+nb+nc >= 10) return true;
        else {
            a /= 10;
            b /= 10;
            c /= 10;
            sum = a+b+c;
        }
    }
    return false;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int max_sum = INT_MIN;
    bool exist = false;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i != j) {
                for(int k=0; k<n; k++) {
                    if(k != i && k != j) {
                        if(!FindCarry(arr[i], arr[j], arr[k])) {
                            max_sum = max(max_sum, arr[i]+arr[j]+arr[k]);
                            exist = true;
                        }
                    }
                }
            }
        }
    }

    if(exist) cout << max_sum;
    else cout << -1;

    return 0;
}