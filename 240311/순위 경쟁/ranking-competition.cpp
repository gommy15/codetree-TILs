#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100

int ranks[MAX_N+1];
int n, s;
char c;

int main() {
    // 여기에 코드를 작성해주세요.
    int an=0, bn=0, cn=0;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> c>>s;
        if(c == 'A') an += s;
        else if (c == 'B') bn += s;
        else cn += s;

        if(an > bn && an > cn) {
            ranks[i] = 1;
        } else if (bn > an && bn > cn) {
            ranks[i] = 2;
        } else if (cn > an && cn > bn)
            ranks[i] = 3;
        else if (an == bn && an > cn)
            ranks[i] = 4;
        else if (an == cn && an > bn)
            ranks[i] = 5;
        else if (bn == cn && bn > an)
            ranks[i] = 6;
        else if (an == bn && bn == cn)
            ranks[i] = 0;
    }

    int cnt = 0;
    for(int i=0; i<n; i++) {
        if(ranks[i-1] != ranks[i]) cnt++;
    }

    cout << cnt;
    return 0;
}