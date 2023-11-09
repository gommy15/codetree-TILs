#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100

int n;
pair<int, int> spots[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    int x1, x2;
    for(int i=0; i<n; i++) {
        cin >> x1 >> x2;
        spots[i] = make_pair(x1, x2);
    }

    int cnt = 0;
    for(int i=0; i<n; i++) {
        bool match = false;

        for(int j=0; j<n; j++) {
            if(i==j) continue;

            if((spots[i].first <= spots[j].first && spots[i].second >= spots[j].second) || (spots[i].first >= spots[j].first && spots[i].second <= spots[j].second)) {
                match = true;
                break;
            }
        }

        if(!match) cnt++;
    }

    cout << cnt;
    return 0;
}