#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1000

int n;
int arr[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >>n;
    for(int i=0; i<n-1; i++) {
        cin >> arr[i];
    }

    for(int a=1; a<=MAX_N; a++) {
        bool exist = true;
        int tmp[MAX_N] = {};
        tmp[0] = a;
        for(int i=0; i<n-1; i++) {
            if((arr[i] - tmp[i] <= 0) || (count(tmp, tmp+n, arr[i] - tmp[i]) == 1)) {
                exist = false;
                break;
            }
            tmp[i+1] = arr[i] - tmp[i];
        }

        if(exist){
            for(int i=0; i<n; i++) {
                cout << tmp[i] << ' ';
            }
            break;
        }
        
    }
    return 0;
}