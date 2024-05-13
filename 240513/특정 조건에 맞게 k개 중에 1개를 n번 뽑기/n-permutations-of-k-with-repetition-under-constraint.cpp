#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> num;

void PrintNum() {
    for(int i=0; i<n; i++) {
        cout << num[i] << ' ';
    }
    cout << '\n';
}

void FindNum(int cur) {
    if(cur >= n) {
        PrintNum();
        return;
    }

    for(int i=1; i<=k; i++) {
        if(count(num.begin(), num.end(), i) < 2) {
            num.push_back(i);
            FindNum(cur+1);
            num.pop_back();
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> k>>n;

    FindNum(0);
    return 0;
}