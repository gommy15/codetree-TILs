#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_AR 100

int n, k;
int arr[MAX_AR];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>k;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int max_num = -1;
    for(int i=0; i<n; i++) {
        for(int j=1; j<k; j++) {
            if(arr[i] == arr[i+k]) {
                max_num = max(max_num, arr[i]);
            }
        }
    }

    cout << max_num;
    return 0;
}