#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int x, y;

bool Is_Pellen(string num) {
    for(int i=0; i=num.size()/2; i++) {
        if(num[i] != num[num.size()-1-i])  {
            return false;
        }
    }
    return true;
}

bool Is_Pellen2(string num) {
    string rev_num = num;
    reverse(rev_num.begin(), rev_num.end());
    return rev_num == num;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> x>>y;

    int cnt = 0;
    for(int i=x; i<=y; i++) {
        string num = to_string(i);

        if(Is_Pellen2(num)) cnt++;
    }

    cout << cnt;
    return 0;
}