#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100

int n, a=0, b=0;
int wins[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    char ch;
    int score;
    for(int i=0; i<n; i++) {
        cin >> ch>>score;
        if(ch == 'A') a += score;
        else b += score;

        if(a>b) wins[i] = 1;
        else if (a<b) wins[i] = 2;
        else wins[i] = 0;
    }

    int cnt = 1;
    for(int i=1; i<n; i++) {
        if(wins[i-1] != wins[i]) cnt++;
    }

    cout << cnt;
    return 0;
}