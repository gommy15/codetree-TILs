#include <iostream>
#include <queue>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    priority_queue<int> pq;

    int num;
    for(int i=0; i<n; i++) {
        cin >> num;
        pq.push(-num);

        if(pq.size() < 3) {
            cout << -1 << '\n';
        } else {
            int n1 = -pq.top();
            pq.pop();
            int n2 = -pq.top();
            pq.pop();

            int ans = -pq.top();

            ans = ans*n1*n2;
            pq.push(-n1);
            pq.push(-n2);

            cout << ans << '\n';
        }
    }

    return 0;
}