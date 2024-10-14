#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<int> pq;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        int num;
        cin >> num;
        pq.push(num);
    }

    while((int)pq.size() > 1) {
        int n1 = pq.top();
        pq.pop();
        int n2 = pq.top();
        pq.pop();

        if((n1-n2) != 0) {
            pq.push(n1-n2);
        }
    }

    cout << pq.top();
    return 0;
}