#include <iostream>
#include <vector>
using namespace std;

int n;
int ans = 0;
vector<int> nums;

void Simulate(int cur_num) {
    if(cur_num == n+1) {
        ans++;
        return;
    }

    for(int i=1; i<=4; i++) {
        if(cur_num+i <= n+1) {
            for(int j=0; j<i; j++) {
                nums.push_back(i);
            }
            Simulate(cur_num+i);
            for(int j=0; j<i; j++) {
                nums.pop_back();
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    Simulate(1);

    cout << ans;
    return 0;
}