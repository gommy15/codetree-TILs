#include <iostream>
#include <vector>
using namespace std;

int n, ans;
vector<int> nums;

void MakeNum(int cnt) {
    if(cnt == n) {
        ans++;
        return;
    }

    for(int i=1; i<=4; i++) {
        if(cnt+i <= n) {
            for(int j=0; j<i; j++) {
                nums.push_back(i);
            }
            MakeNum(cnt+i);
            for(int j=0; j<i; j++) {
                nums.pop_back();
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    MakeNum(0);

    cout << ans;
    return 0;
}