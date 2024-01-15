#include <iostream>
#include <algorithm>
using namespace std;

int arr[101];
int n, k;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>k;

    int a, b;
    for(int i=0; i<k; i++) {
        cin >> a>>b;
        for(int j=a; j<=b; j++) {
            arr[j] += 1;
        }
    }

    int max_num = *max_element(arr, arr+n);
    cout << max_num;
    return 0;
}