#include <iostream>
using namespace std;

int x;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> x;
    int t = 0, v = 0, len = 0;

    while(true) {
        t += 2;
        v++;
        len += 2*v;
        // cout << t << ' ' << v << ' ' << len << endl;
        if(len == x) break;
        if(len > x) {
            len -= 2*v;
            v--;
            t -= 2;
            break;
        }
    }

    if(len == x) cout << t;
    else if(len + 2*v == x) cout << t+2;
    else cout << t+1;

    // while(true) {
    //     if(len == x) break;
    //     if(len < x/2) {
    //         v++;
    //     } else {
    //         if(v != 1) v--;
    //     }

    //     len += v;
    //     t++;
    //     cout << t << ' ' << v << ' ' << len << endl;
    // }

    return 0;
}