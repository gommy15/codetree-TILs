#include <iostream>
using namespace std;

int a, b, c;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a>>b>>c;

    int diff = (a*24*60 + b*60+c) - (11*24*60 + 11*60 + 11);

    if(diff < 0) cout << -1;
    else cout << diff;

    
    return 0;
}