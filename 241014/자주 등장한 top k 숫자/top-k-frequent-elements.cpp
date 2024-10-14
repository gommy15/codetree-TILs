#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int n, k;
unordered_map<int, int> um;
vector<pair<int, int>> nums;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>k;

    for(int i=0; i<n; i++) {
        int num;
        cin >> num;
        um[num]++;
    }

    for(const auto& pair : um) {
        nums.push_back({-pair.second, -pair.first});
    }

    sort(nums.begin(), nums.end());

    for(int i=0; i<k; i++) {
        cout << -nums[i].second << ' ';
    }
    return 0;
}