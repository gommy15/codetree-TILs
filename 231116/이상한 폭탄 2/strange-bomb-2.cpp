#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n, k;
int arr[101];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>k;

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int max_num = -1;

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<=i+k; j++) {
            if(arr[i] == arr[j]) {
                max_num = max(max_num, arr[i]);
            }
        }
    }

    cout << max_num;
    return 0;
}