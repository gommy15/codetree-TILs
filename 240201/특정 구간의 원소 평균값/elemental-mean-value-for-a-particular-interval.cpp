#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100

int n;
int arr[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int sum = 0;
            for(int k=i; k<=j; k++) {
                sum += arr[k];
            }
            // 나누기를 했을 때 double 형인지가 중요하다!!
            // count를 사용하는 방법이 유용한듯! 기억해두자!
            bool exist = count(arr, arr+n, (double)sum/abs(j-i+1)) >0;
            if(exist) cnt++;
        }
    }

    cout << cnt;
    return 0;
}