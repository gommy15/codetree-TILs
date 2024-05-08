#include <iostream>
#include <vector>
using namespace std;

int k, n;
vector<int> ans;

void Make_num(int curr) {
    if(curr > n) {
        for(int i=0; i<n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';

        return;
    }

    for(int i=1; i<=k; i++) {
        ans.push_back(i);
        Make_num(curr+1);
        ans.pop_back();
    }
} 

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> k>>n;

    Make_num(1);
    return 0;
}