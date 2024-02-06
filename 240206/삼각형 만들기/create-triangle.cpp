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
    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x>>y;
        spot[i] = make_pair(x, y);
    }

    int max_area = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            // if(i==j) continue;
            for(int k=j+1; k<n; k++) {
                // if(k==i || k==j) continue;

                int x1 = spot[i].first;
                int y1 = spot[i].second;
                int x2 = spot[j].first;
                int y2 = spot[j].second;
                int x3 = spot[k].first;
                int y3 = spot[k].second;

                if((x1 == x2 || x2 == x3 || x3 == x1) && (y1==y2 || y2==y3 || y3==y1)) {
                    int area = abs((x1*y2 + x2*y3 + x3*y1) - (x2*y1 + x3*y2 + x1*y3));
                    max_area = max(max_area, area);
                }
            }
        }
    }

    cout << max_area;
    return 0;
}