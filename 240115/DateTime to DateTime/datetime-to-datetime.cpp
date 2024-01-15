#include <iostream>
using namespace std;

int a, b, c;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a>>b>>c;

    int day = 11, hour=11, min=11, time = 0;
    while(true) {
        if(day == a && hour == b && min == c) break;

        time++;
        min++;

        if(min == 60) {
            hour++;
            min = 0;
            if(hour == 24) {
                day++;
                hour=0;
            }
        }
    }

    cout << time;
    return 0;
}