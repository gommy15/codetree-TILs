#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 100

int n;
int house[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> house[i];
    }

    int min_sum = INT_MAX;
    for(int i=0; i<n; i++) {
        int sum = 0;
        for(int j=0; j<n; j++) {
            if(i==j) continue;

            sum += (abs(j-i) * house[j]);
        }

        min_sum = min(min_sum, sum);
    }

    cout << min_sum;
    return 0;
}