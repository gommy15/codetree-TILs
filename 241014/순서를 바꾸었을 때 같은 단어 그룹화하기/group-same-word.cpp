#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

int n, ans;
unordered_map<string, int> mp;


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        sort(str.begin(), str.end());
        mp[str]++;
    }

    for(const auto& pair : mp) {
        ans = max(ans, pair.second);
    }

    cout << ans;
    return 0;
}