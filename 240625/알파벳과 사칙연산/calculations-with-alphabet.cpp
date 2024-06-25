#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
using namespace std;
#define MAX_N 100
#define ALPHA_NUMS 6

string str;
int alpha_nums[ALPHA_NUMS];
vector<char> alpha;
int ans = INT_MIN;

int Calc() {
    int result = alpha_nums[str[0]-'a'];

    for(int i=1; i<(int)str.size(); i+=2) {
        switch(str[i]){
            case '+':
                result += alpha_nums[str[i+1]-'a'];
                break;
            case '-':
                result -= alpha_nums[str[i+1]-'a'];
                break;
            case '*':
                result *= alpha_nums[str[i+1]-'a'];
                break;
        }
    }

    return result;
}

void MatchNum(int cnt) {
    if(cnt == (int)alpha.size()) {
        ans = max(ans, Calc());
        return;
    }

    for(int i=1; i<=4; i++) {
        alpha_nums[alpha[cnt]-'a'] = i;
        MatchNum(cnt+1);
    }

    // for(int i=1; i<=4; i++) {
    //     alpha.push_back(i);
    //     MatchNum(cnt+1);
    //     alpha.pop_back();
    // }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> str;

    for(int i=0; i<(int)str.size(); i+=2) {
        // if(find(alpha.begin(), alpha.end(), str[i]) == alpha.end())
        //     alpha.push_back(str[i]);
        alpha.push_back(str[i]);
    }

    sort(alpha.begin(), alpha.end());
    alpha.erase(unique(alpha.begin(), alpha.end()), alpha.end());
    
    MatchNum(0);

    cout << ans;
    return 0;
}