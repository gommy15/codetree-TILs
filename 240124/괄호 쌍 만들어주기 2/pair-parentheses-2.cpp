#include <iostream>
#include <string>
using namespace std;

string str;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> str;

    int cnt = 0;
    for(int i=0; i<str.size(); i++) {
        if(str[i] == '(' && str[i+1] == '(') {
            for(int j=i+2; j<str.size(); j++) {
                if(str[j] == ')' && str[j+1] == ')') cnt++;
            }
        }
    }

    cout << cnt;
    return 0;
}