#include <iostream>
using namespace std;
#define MAX_N 10000

int n;
int arr[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    int sum = 0;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    int avg = sum/n;

    int cnt = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] > avg) {
            cnt += (arr[i]-avg);
        }
    }

    cout << cnt;
    return 0;
}