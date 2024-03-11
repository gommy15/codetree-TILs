#include <iostream>
#include <algorithm>
using namespace std;

int x1, y1, x2, y2, a1, b1, a2, b2;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> x1>>y1>>x2>>y2>>a1>>b1>>a2>>b2;

    cout << (max(x2, a2) - min(x1, a1)) * (max(y2, b2) - min(y1, b1));
    return 0;
}