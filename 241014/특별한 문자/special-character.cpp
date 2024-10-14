#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

string str;
unordered_map<char, int> up;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> str;

    for(char s : str) {
        up[s]++;
    }

    for(char s : str) {
        if(up[s] == 1) {
            cout << s;
            return 0;
        }
    }

    cout << "None";
    return 0;
}