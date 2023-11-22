#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int x, y;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> x>>y;

    int max_sum = INT_MIN;

    for(int i=x; i<=y; i++) {
        int sum = 0;
        int num = i;
        while(num != 0) {
            sum += (num%10);
            num /= 10;
            // cout << i << '\n';
        }
        max_sum = max(max_sum, sum);
    }

    cout << max_sum;
    return 0;
}