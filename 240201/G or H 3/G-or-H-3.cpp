#include <iostream>
using namespace std;
#define MAX_ARR 10000

int n, k;
int arr[MAX_ARR+1];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>k;

    int idx;
    char alpa;

    for(int i=0; i<n; i++) {
        cin >> idx>>alpa;
        if(alpa == 'G') arr[idx] = 1;
        else arr[idx] = 2;
    }

    int max_sum = 0;
    for(int i=0; i<=MAX_ARR-k; i++) {
        int sum = 0;
        for(int j=i; j<=i+k; j++) {
            sum += arr[j];
        }
        max_sum = max(max_sum, sum);
    }

    cout << max_sum;
    return 0;
}