#include <iostream>
#include <algorithm>
using namespace std;

int a, b, c;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a>>b>>c;

    int max_sum = 0;
    for(int i=0; i*a <= c; i++) {
        int sum = a*i;

        int b_cnt = (c-sum)/b;

        sum += b*b_cnt;

        max_sum = max(max_sum, sum);
    }

    cout << max_sum;
    return 0;
}