#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 1000

int n;
int hill[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> hill[i];
    }

    int max_h = *max_element(hill, hill+n);
    int min_h = *min_element(hill, hill+n);

    int min_cost = INT_MAX;
    for(int a=min_h; a<=max_h; a++) {
        int cost = 0;
        for(int i=0; i<n; i++) {
            int x;
            if(a <= hill[i] && hill[i] <= a+17) continue;
            if(hill[i] < a) {
                x = a-hill[i];
            } else {
                x = hill[i] - a - 17;
            }

            cost += (x*x);
        }

        min_cost = min(min_cost, cost);
    }

    cout << min_cost;
    return 0;
}