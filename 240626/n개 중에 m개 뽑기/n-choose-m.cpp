#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> nums;

void Print() {
    for(int i=0; i<nums.size(); i++) {
        cout << nums[i] << ' ';
    }
    cout << '\n';
}

void MakeNum(int cnt, int num) {
    if(cnt == m) {
        Print();
        return;
    }

    for(int i=num+1; i<=n; i++) {
        nums.push_back(i);
        MakeNum(cnt+1, i);
        nums.pop_back();
    }
}


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;

    MakeNum(0, 0);

    return 0;
}