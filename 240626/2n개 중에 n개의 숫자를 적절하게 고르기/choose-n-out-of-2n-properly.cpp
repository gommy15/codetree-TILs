#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 10

int n;
int nums[2*MAX_N];
vector<int> select_num;

int sum=0, ans = INT_MAX;

int Calc() {
    int a_sum = 0;
    for(int i=0; i<select_num.size(); i++) {
        a_sum += select_num[i];
    }

    return abs(a_sum - (sum-a_sum));
}

void FindMinDiff(int cnt, int cur_idx) {
    if(cnt == n) {
        ans = min(ans, Calc());
        return;
    }

    for(int i=cur_idx; i<2*n; i++) {
        select_num.push_back(nums[cur_idx]);
        FindMinDiff(cnt+1, i);
        select_num.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i=0; i<2*n; i++) {
        cin >> nums[i];
        sum += nums[i];
    }

    FindMinDiff(0, 0);

    cout << ans;
    return 0;
}