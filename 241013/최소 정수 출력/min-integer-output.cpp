#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    int x;
    while(n--) {
        cin >> x;

        if(x == 0) {
            if(pq.empty()) {
                cout << 0 << '\n';
                continue;
            }
            cout << pq.top() << '\n';
            pq.pop();
        }else {
            pq.push(x);
        }
    }
    return 0;
}