#include <iostream>
using namespace std;

int x1, x2, x3, x4;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> x1>>x2>>x3>>x4;

    if((x1 <= x3 && x3 <= x2) || (x1 <= x4 && x4 <= x2)) {
        cout << "intersecting" << endl;
    } else {
        cout << "nonintersecting" << endl;
    }
    return 0;
}