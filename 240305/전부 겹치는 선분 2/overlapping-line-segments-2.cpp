#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100
#define MAX_X 100

int n;
int x1[MAX_N], x2[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> x1[i]>>x2[i];
    }

    bool overlap = false;
    for(int i=0; i<n; i++) {
        int max_x1 = 0, min_x2 = 101;
        for(int j=0; j<n; j++) {
            if(i == j) continue;
            max_x1 = max(max_x1, x1[j]);
            min_x2 = min(min_x2, x2[j]);
        }

        if(min_x2 >= max_x1) {
            overlap = true;
            break;
        }
        
    }

    if(overlap) cout << "Yes";
    else cout << "No";
    return 0;
}