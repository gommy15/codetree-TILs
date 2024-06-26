#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_N 20

int n, m, ans;
int nums[MAX_N];
vector<int> cnums;

int Calc() {
    int result = 0;
    for(int i=0; i<cnums.size(); i++) {
        result ^= cnums[i];
    }

    return result;
}

void ChooseNum(int cnt, int idx) {
    if(cnt == m) {
        ans = max(ans, Calc());
        return;
    }

    for(int i=idx; i<n; i++) {
        cnums.push_back(nums[i]);
        ChooseNum(cnt+1, i+1);
        cnums.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;

    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    ChooseNum(0, 0);

    cout << ans;

    return 0;
}