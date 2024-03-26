#include <iostream>
#include <string>
using namespace std;
#define MAX_STR 10

int n;
string str;

void Shift() {
    char tmp[MAX_STR+1] = {};

    for(int i=1; i<n; i++) {
        tmp[i] = str[i-1];
    }
    tmp[0] = str[n-1];
    
    for(int i=0; i<n; i++) {
        str[i] = tmp[i];
    }
    // cout << str << '\n';
}

int Encoding() {
    int cnt = 1;
    string en = "";
    for(int i=1; i<n; i++) {
        if(str[i-1] != str[i]) {
            // cout << cnt << ' ';
            en += str[i-1];
            en += to_string(cnt);
            cnt = 1;
        } else {
            cnt++;
        }
    }
    en += str[-1];
    en += to_string(cnt);

    // cout << "\n***" << en << '\n';

    return en.size();
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> str;
    n = str.size();

    int ans = 10;

    for(int i=0; i<n; i++) {
        Shift();
        ans = min(ans, Encoding());
    }

    cout << ans;
    
    return 0;
}