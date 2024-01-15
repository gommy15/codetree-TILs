#include <iostream>
using namespace std;

int num_of_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int m1, m2, d1, d2;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> m1>>d1>>m2>>d2;

    int month = m1, days = d1, cnt = 1;
    while(true) {
        if(month == m2 && days == d2) break;
        
        days++;
        cnt++;
        
        if(days == num_of_days[month]) {
            month++;
            days = 0;
        }
    }

    cout << cnt;
    return 0;
}