#include <iostream>
#include <algorithm>
using namespace std;

int n, a, b, c;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    int max_score = 0;
    for(int i=1; i<=3; i++) {
        int cups[4] = {};
        cups[i] = 1;

        int score = 0;
        for(int j=0; j<n; j++) {
            cin >> a>>b>>c;
            int tmp = cups[a];
            cups[a] = cups[b];
            cups[b] = tmp;

            if(cups[c] == 1) score++;
        }

        max_score = max(max_score, score);
    }

    cout << max_score;
    return 0;
}