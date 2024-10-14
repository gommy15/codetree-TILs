#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<int> pq;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    
    int x;
    while(n--) {
        cin >> x;

        if(x > 0) {
            pq.push(x);
        } else {
            if(pq.empty()) {
                cout << 0 << '\n';
            } else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }


    return 0;
}