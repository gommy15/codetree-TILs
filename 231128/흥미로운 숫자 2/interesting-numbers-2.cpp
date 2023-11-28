#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int x, y;

int main() {
    cin >> x>>y;

    int cnt = 0;
    for(int i=x; i<= y; i++) {
        int num = i;
        int digit[10] = {};
        int all_digits = 0;
        while(num != 0) {
            digit[num%10]++;
            all_digits++;
            num /= 10;
        }

        bool interest = false;

        int max_num = *max_element(digit, digit+10);
        if((max_num +1) == all_digits) cnt++;
    }

    cout << cnt;
    return 0;
}