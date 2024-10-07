#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> num;
int ans = 0;

void MakeNum(int cnt) {
    if(cnt == n) {
        ans++;
        return;
    }

    for(int i=1; i<=4; i++) {
        if(n-cnt >= i) {
            for(int j=0; j<i; j++) {
                num.push_back(i);
            }
            MakeNum(cnt+i);
            for(int j=0; j<i; j++) {
                num.pop_back();
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