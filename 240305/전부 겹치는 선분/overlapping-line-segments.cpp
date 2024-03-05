#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100
#define MAX_X 100

int n;
int x1[MAX_N], x2[MAX_N];
int arr[MAX_X+1];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x1[i] >> x2[i];
    }

    for(int i=0; i<n; i++){
        for(int j=x1[i]; j<=x2[i]; j++) {
            arr[j]++;
        }
    }

    int max_over = *max_element(arr, arr+MAX_X+1);

    if(max_over == n) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}