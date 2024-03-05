#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int x1, x2, y1, y2, a1, a2, b1, b2;
    cin >>x1>>y1>>x2>>y2>>a1>>b1>>a2>>b2;

    if(x2 < a1 || a2 < x1 || b1 > y2 || y1 > b2) {
        cout << "nonoverlapping" << endl;
    }else {
        cout << "overlapping" << endl;
    }
    return 0;
}