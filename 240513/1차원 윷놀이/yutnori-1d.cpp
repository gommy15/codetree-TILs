#include <iostream>
#include <algorithm>

using namespace std;
#define MAX_N 12
#define MAX_K 4

int n, m, k;
int nums[MAX_N], pieces[MAX_K];

int ans;

int Calc() {
    int score = 0;
    for(int i=0; i<k; i++) {
        score += (pieces[i] >= m);
    }

    return score;
}

void FindMax(int cur) {
    // 항상 답 갱신
    ans = max(ans, Calc());

    if(cur == n) return;

    for(int i=0; i<k; i++) {
        // 점수를 얻은 말은 움직이지 않기!
        if(pieces[i] >= m) continue;

        pieces[i] += nums[cur];
        FindMax(cur+1);
        pieces[i] -= nums[cur];
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m>>k;
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    for(int i=0; i<k; i++) {
        pieces[i] = 1;
    }

    FindMax(0);

    cout << ans;
    return 0;
}