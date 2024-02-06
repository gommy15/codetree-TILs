#include <iostream>
#include <algorithm>
#include <climits>
#include <utility>
using namespace std;
#define MAX_N 100

int n;
pair<int, int> spot[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    int x, y;
    for(int i=0; i<n; i++) {
        cin >> x>>y;
        spot[i] = make_pair(x, y);
    }

    int min_dis = INT_MAX;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i == j) continue;
            int x1 = spot[i].first;
            int y1 = spot[i].second;
            int x2 = spot[j].first;
            int y2 = spot[j].second;

            int dis = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
            min_dis = min(min_dis, dis);
        }
    }

    cout << min_dis;
    return 0;
}