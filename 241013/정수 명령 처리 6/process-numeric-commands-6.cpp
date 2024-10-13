#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    priority_queue<int> pq;
    string ord;
    int k;

    while(n--) {
        cin >> ord;
        if(ord == "push") {
            cin >> k;
            pq.push(k);
        }else if (ord == "pop") {
            cout << pq.top()<<'\n';
            pq.pop();
        }else if (ord == "size") {
            cout << (int)pq.size() << '\n';
        }else if (ord == "empty") {
            cout << (int)pq.empty() << '\n';
        }else {
            cout << pq.top() << '\n';
        }
    }
    return 0;
}