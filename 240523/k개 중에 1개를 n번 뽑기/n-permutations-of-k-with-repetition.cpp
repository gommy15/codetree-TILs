#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> nums;

void PrintNum() {
    for(int i=0; i<n; i++) {
        cout << nums[i] << ' ';
    }
    cout << '\n';
}

void MakeNum(int cnt) {
    if(cnt == n){
        PrintNum();
        return;
    }

    for(int i=1; i<=k; i++) {
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