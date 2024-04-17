#include <iostream>
#include <string>
#include <list>
using namespace std;

list<int> s;
int n;
string str;


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    int num;
    for(int i=0; i<n; i++) {
        cin >> str;
        if(str == "push_front") {
            cin >> num;
            s.push_front(num);
        } else if (str == "push_back") {
            cin >> num;
            s.push_back(num);
        } else if (str == "pop_front") {
            cout << s.front() << '\n';
            s.pop_front();
        } else if (str == "pop_back") {
            cout << s.back() << '\n';
            s.pop_back();
        } else if (str == "size") {
            cout << s.size() << '\n';
        } else if (str == "empty") {
            cout << s.empty() << '\n';
        } else if (str == "front") {
            cout << s.front() << '\n';
        } else if (str == "back") {
            cout << s.back() << '\n';
        }
    }


    return 0;
}