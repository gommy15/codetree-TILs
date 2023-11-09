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

    sort(spots, spots+n);

    int cnt = 0;
    for(int i=0; i<n; i++) {
        x1 = spots[i].first;
        x2 = spots[i].second;

        int start = spots[i+1].first;
        int end = spots[i+1].second;
        bool match = false;
        for(int j=start; j<=end; j++) {
            if((j-start)/(end-start) == (j-x1)/(x2-x1)) {
                match = true;
                break;
            }
        }
        if(!match) cnt++;
    }

    cout << cnt;
    return 0;
}