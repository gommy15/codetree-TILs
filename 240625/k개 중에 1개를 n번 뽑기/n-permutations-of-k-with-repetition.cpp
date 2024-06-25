#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> ans;

void PrintNum() {
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

void Simulate(int cur_num) {
    if(cur_num == n) {
        PrintNum();
        return;
    }

    for(int i=1; i<=k; i++) {
        ans.push_back(i);
        Simulate(cur_num+1);
        ans.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> k>>n;

    Simulate(0);
    return 0;
}