#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> nums;

void Print() {
    for(int i=0; i<n; i++) {
        cout << nums[i] << ' ';
    }
    cout << '\n';
}

void MakeNum(int cnt) {
    if(cnt == n) {
        Print();
        return;
    }

    for(int i=1; i<=k; i++) {
        if(cnt >= 2 && nums[cnt-1] == i && nums[cnt-2] == i) continue;
        nums.push_back(i);
        MakeNum(cnt+1);
        nums.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> k>>n;

    MakeNum(0);
    return 0;
}