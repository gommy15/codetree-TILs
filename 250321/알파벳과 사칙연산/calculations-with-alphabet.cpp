#include <iostream>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;

#define MAX_N 6

int n = 6;

string exp;
int num[MAX_N];
int ans = INT_MIN;

int Conv(int idx) {
    return num[exp[idx]-'a'];
}

int Calc() {
    int leng = (int)exp.size();
    int value = Conv(0);

    for(int i=2; i<leng; i+=2) {
        if(exp[i-1] == '+') value += Conv(i);
        else if(exp[i-1] == '-') value -= Conv(i);
        else value *= Conv(i);
    }

    return value;
}

void FindMax(int idx) {
    if(idx == n) {
        ans = max(ans, Calc());
        return;
    }

    for(int i=1; i<=4; i++) {
        num[idx] = i;
        FindMax(idx + 1);
    }
}

int main() {
    cin >> exp;

    FindMax(0);
    
    cout << ans;

    return 0;
}