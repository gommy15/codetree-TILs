#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N   20

int n;
int arr[MAX_N];

// carry를 찾으면 true, 아니면 false
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

    int max_sum = -1;
    // int max_sum = INT_MIN;
    //모두 캐리만 나오는 조합들만 있으면
    // bool exist = false;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i != j) {
                for(int k=0; k<n; k++) {
                    if(k != i && k != j) {
                        // carry를 찾지 못하면
                        if(!FindCarry(arr[i], arr[j], arr[k])) {
                            max_sum = max(max_sum, arr[i]+arr[j]+arr[k]);
                            // exist = true;
                        }
                    }
                }
            }
        }
    }

    // 양수 조합들의 합이기 떄문에 음수값이 나올 수 없다
    // max_sum의 초기값을 -1로 한다면 굳이 변수를 하나 더 만들어 검증을 거칠 필요가 없다.
    cout << max_sum;
    // if(exist) cout << max_sum;
    // else cout << -1;

    return 0;
}