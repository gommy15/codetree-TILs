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
    int abc = nums[6];
    int bc = nums[5];
    int a = abc - bc;
    int ac = nums[4];
    int c = ac - a;
    int b = bc - c;

    cout << a << ' ' << b << ' ' << c;
    return 0;
}