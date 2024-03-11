#include <iostream>
#include <algorithm>
using namespace std;
#define ARR_N 15

int arr[15];

int main() {
    // 여기에 코드를 작성해주세요.
    for(int i=0; i<ARR_N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+ARR_N);

    // 오름차순으로 정렬하면 차례대로 a, b, c의 값이다.
    int a = arr[0];
    int b = arr[1];
    int c = arr[2];
    int d = arr[ARR_N-1]-a-b-c;

    cout << a << ' ' << b << ' ' << c << ' ' << d;
    return 0;
}