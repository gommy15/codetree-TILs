#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a, b, c, d;
    cin >> a>>b>>c>>d;

    if(b<c || d<a) {
        cout << (d-c) + (b-a) << endl;
    } else {
        // int tmp[101] = {};
        // for(int i=a; i<b; i++) {
        //     tmp[i] = 1;
        // }
        // for(int i=c; i<d; i++) {
        //     tmp[i] = 1;
        // }

        // int cnt = 0;
        // for(int i=0; i<101; i++) {
        //     if(tmp[i] == 1) cnt++;
        // }

        // cout << cnt;


        // 간단한 방법
        cout << max(b, d) - min(a, c) << endl;
    }
    return 0;
}