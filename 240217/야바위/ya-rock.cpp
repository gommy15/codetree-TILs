#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100

int n;
int a[MAX_N], b[MAX_N], c[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i]>>b[i]>>c[i];
    }

    int max_score = 0;
    for(int i=1; i<=3; i++) {
        int cups[4] = {};
        cups[i] = 1;
        
        int score = 0;
        for(int j=0; j<n; j++) {
            int tmp = cups[a[j]];
            cups[a[j]] = cups[b[j]];
            cups[b[j]] = tmp;

            if(cups[c[j]] == 1) score++;
        }

        max_score = max(max_score, score);
    }

    cout << max_score;
    return 0;
}