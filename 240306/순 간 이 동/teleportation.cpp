#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int a, b, x, y;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a>>b>>x>>y;

    int min_len = INT_MAX;
    // 1. a에서 b로 바로 갔을 경우
    int len = abs(b-a);
    min_len = min(min_len, len);

    //2. x위치에서 y위치로 순간이동한 경우
    len = abs(x-a) + abs(y-b);
    min_len = min(min_len, len);

    //3. y위치에서 x위치로 순간이동 한 경우
    len = abs(y-a) + abs(x-b);
    min_len = min(min_len, len);

    cout << min_len;
    return 0;
}