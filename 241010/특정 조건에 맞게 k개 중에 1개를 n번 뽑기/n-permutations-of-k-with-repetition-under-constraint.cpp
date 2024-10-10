#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
vector<int> ans;

void Print() {
    for(int i=0; i<(int)ans.size(); i++) {
        cout << ans[i] << ' ';
    }

    cout << '\n';
}

void MakeNum(int cnt) {
    if(cnt == n) {
        Print();
        return;
    }

    for(int i=1; i<=k; i++) {
        if((int)ans.size() >= 3 && (ans[cnt] == ans[cnt-1] && ans[cnt-1] == ans[cnt-2])) continue;

        ans.push_back(i);
        MakeNum(cnt+1);
        ans.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> k>>n;

    MakeNum(0);

    return 0;
}