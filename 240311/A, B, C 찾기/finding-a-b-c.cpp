#include <iostream>
#include <algorithm>
using namespace std;

int nums[7];

int main() {
    // 여기에 코드를 작성해주세요.
    for(int i=0; i<7; i++) {
        cin >> nums[i];
    }

    sort(nums, nums+7);
    // 2차 풀이
    // 오름차순으로 정렬했을 때, 가장 작은 수는 A, 두번째로 작은 수는 항상 B이다.
    int a = nums[0];
    int b = nums[1];

    // 오름차순으로 정렬했을 때, 가장 큰 수는 항상 a+b+c이다.
    int c = nums[6]-a-b;

    // 1차 풀이
    // int abc = nums[6];
    // int bc = nums[5];
    // int a = abc - bc;
    // int ac = nums[4];
    // int c = ac - a;
    // int b = bc - c;

    cout << a << ' ' << b << ' ' << c;
    return 0;
}