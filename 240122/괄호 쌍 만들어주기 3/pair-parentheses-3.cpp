#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

string str;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> str;

    int cnt = 0;
    for(int i=0; i<str.size(); i++) {
        if(str[i] == '(') {
            for(int j=i+1; j<str.size(); j++) {
                if(str[j] == ')') cnt++;
            }
        }
    }

    cout << cnt;
    return 0;
}