#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int arr[6];

int main() {
    // 여기에 코드를 작성해주세요.
    int total = 0;
    for(int i=0; i<6; i++) {
        cin >> arr[i];
        total += arr[i];
    }

    int min_diff = INT_MAX;
    for(int i=0; i<4; i++) {
        for(int j=i+1; j<5; j++) {
            for(int k=j+1; k<6; k++) {
                int sum1 = arr[i] + arr[j] + arr[k];
                int sum2 = total - sum1;

                min_diff = min(min_diff, abs(sum1 - sum2));
            }
        }
    }

    cout << min_diff;
    return 0;
}