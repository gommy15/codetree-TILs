#include <iostream>
using namespace std;

int a, b, c;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a>>b>>c;

    // int diff = (a*24*60 + b*60+c) - (11*24*60 + 11*60 + 11);

    // if(diff < 0) cout << -1;
    // else cout << diff;

    // 시초
    if (a < 11) cout << -1;
    else if (b < 11) cout << -1;
    else if (c < 11) cout << -1;

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