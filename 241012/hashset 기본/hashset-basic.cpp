#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int n;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    unordered_set<int> hashset;
    while(n--) {
        string str;
        int num;
        cin >> str>> num;

        if(str == "add") {
            hashset.insert(num);
        } else if (str == "remove") {
            hashset.erase(num);
        } else {
            if(hashset.find(num) != hashset.end()) {
                cout << "true\n";
            } else cout << "false\n";
        }

    }
    return 0;
}