#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <tuple>
#include <functional>
using namespace std;

int n, m;
priority_queue<tuple<int, int, int>> spots;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;

    int x, y;
    for(int i=0; i<n; i++) {
        cin >> x>>y;
        spots.push(make_tuple(-(abs(x)+abs(y)), -x, -y));
    }

    while(m--) {
        tie(ignore, x, y) = spots.top();
        spots.pop();

        x = -x;
        y = -y;

        x+=2; y+=2;

        spots.push({-(abs(x)+abs(y)), -x, -y});
    }

    tie(ignore, x, y) = spots.top();

    cout << -x << ' ' << -y;
    return 0;
}