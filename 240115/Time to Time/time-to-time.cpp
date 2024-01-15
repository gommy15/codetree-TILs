#include <iostream>
using namespace std;

int a, b, c, d;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a>>b>>c>>d;

    int hour = a;
    int min = b;
    int time = 0;
    while(true) {
        if(hour == c && min == d) break;
        
        time++;
        min++;

        if(min == 60) {
            min = 0;
            hour++;
        }
    }

    cout << time;
    return 0;
}