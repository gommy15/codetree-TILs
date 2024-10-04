#include <iostream>
#include <unordered_map>
using namespace std;

int n;

int main() {
    // 여기에 코드를 작성해주세요.
    unordered_map<int, int> m;

    cin >> n;
    while (n--) {
        string str;
        int k, v;

        cin >> str;
        if(str == "add") {
            cin >> k>>v;
            m[k] = v;
        } else if (str == "find") {
            cin >> k;
            if(m.find(k) == m.end()) {
                cout << "None\n";
            } else {
                cout << m[k] << '\n';
            }
        } else {
            cin >> k;
            m.erase(k);
        }
    }

    return 0;
}