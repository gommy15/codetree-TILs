#include <iostream>
#include <string>
using namespace std;

string str;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> str;

    for(int i=0; i<3; i++) {
        cout << str[i];
    }

    cout <<'\n';

    for(int i=str.size()-4; i<str.size(); i++) {
        cout << str[i];
    }
    return 0;
}