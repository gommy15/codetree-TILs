#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string str;
int ans = 0;

vector<int> nums;

int Calc() {
    int result = nums[str[0]-'a'];

    for(int i=1; i<(int)str.size(); i=i+2) {
        switch(str[i]) {
            case '+':
                result += nums[str[i+1]-'a'];
                break;
            case '-':
                result -= nums[str[i+1]-'a'];
                break;
            case '*':
                result *= nums[str[i+1]-'a'];
                break;
        }
    }

    return result;
}

void MakeNums(int cnt) {
    if(cnt == 6) {
        ans = max(ans, Calc());
        return;
    }

    for(int i=1; i<=4; i++) {
        nums.push_back(i);
        MakeNums(cnt+1);
        nums.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> str;

    MakeNums(0);

    cout << ans;
    return 0;
}