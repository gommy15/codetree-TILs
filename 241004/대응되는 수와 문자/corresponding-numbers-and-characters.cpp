#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
#define MAX_N 100000

int n, m;
unordered_map<string, int> stoint;
string words[MAX_N+1];

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n>>m;

    string str;
    for(int i=1; i<=n; i++) {
        cin >> str;
        stoint[str] = i;
        words[i] = str;
    }

    while(m--) {
        string key;
        cin >> key;

        if('0' <= key[0] && key[0] <= '9') {
            cout << words[stoi(key)] << '\n';
        } else {
            cout << stoint[key] << '\n';
        }
    }
    return 0;
}