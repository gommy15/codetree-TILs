#include <iostream>
#include <string>
using namespace std;

int m1, m2, d1, d2;
int num_of_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> m1 >> d1 >> m2 >> d2;

    int days1 = d1, days2 = d2;
    for(int i=1; i<m1; i++) {
        days1 += num_of_month[i];
    }
    for(int i=1; i<m2; i++) {
        days2 += num_of_month[i];
    }

    int diff = days2 - days1;

    while(true) {
        if(diff >=0) break;
        diff += 7;
    }

    string days[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    
    cout << days[diff%7];
    
    return 0;
}