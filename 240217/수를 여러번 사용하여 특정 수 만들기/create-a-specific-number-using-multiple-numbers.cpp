#include <iostream>
#include <algorithm>
using namespace std;

int a, b, c;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a>>b>>c;

    int max_time = c/min(a, b);
    int max_num = 0;
    for(int i=1; i<=max_time; i++) {
        int num = a*i + b*(max_time-i);

        if(num <= c) {
            max_num = max(max_num, num);
        }
    }

    cout << max_num;

    return 0;
}