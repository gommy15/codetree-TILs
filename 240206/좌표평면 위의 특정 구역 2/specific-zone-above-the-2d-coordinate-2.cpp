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

    int min_area = INT_MAX;

    for(int i=0; i<n; i++) {
        int x1 = 40000, x2 = 0, y1 = 40000, y2 = 0;
        for(int j=0; j<n; j++) {
            if(i==j) continue;
            x = spot[j].first;
            y = spot[j].second;

            x1 = min(x1, x);
            x2 = max(x2, x);
            y1 = min(y1, y);
            y2 = max(y2, y);
        }

        int area = (x2-x1) * (y2-y1);
        min_area = min(min_area, area);
    }

    cout << min_area;
    return 0;
}