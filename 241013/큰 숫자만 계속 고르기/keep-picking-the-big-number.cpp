#include <iostream>
#include <queue>
using namespace std;

int n, m;
priority_queue<int> pq;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;

    int num;
    for(int i=0; i<n; i++) {
        cin >> num;
        pq.push(num);
    }

    while(m--) {
        num = pq.top()-1;
        pq.pop();

        pq.push(num);
    }

    cout << pq.top();

    return 0;
}