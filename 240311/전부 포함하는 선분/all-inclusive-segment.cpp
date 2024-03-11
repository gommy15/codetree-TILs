#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 100

int n;
int x1[MAX_N], x2[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x1[i]>>x2[i];
    }

    int min_line = INT_MAX;
    for(int i=0; i<n; i++) {
        int min_x1 = 101;
        int max_x2 = 0;
        for(int j=0; j<n; j++) {
            if(i==j) continue;
            min_x1 = min(min_x1, x1[j]);
            max_x2 = max(max_x2, x2[j]);
        }

        min_line = min(min_line, (max_x2-min_x1));
    }

    cout << min_line;
    return 0;
}