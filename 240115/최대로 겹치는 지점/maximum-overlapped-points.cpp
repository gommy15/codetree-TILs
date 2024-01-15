#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[101];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    int x1, x2;

    for(int i=0; i<n; i++) {
        cin >> x1>>x2;
        for(int j=x1; j<=x2; j++) {
            arr[j] += 1;
        }
    }

    int max_line = *max_element(arr, arr+101);

    cout << max_line;
    return 0;
}