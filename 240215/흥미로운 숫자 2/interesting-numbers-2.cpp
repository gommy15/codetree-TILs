#include <iostream>
#include <algorithm>
using namespace std;

int x, y;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> x>>y;

    int inter_num = 0;
    for(int i=x; i<=y; i++) {
        int numbers[10] = {};

        int num = i;
        int digit = 0;
        while(num) {
            numbers[num%10]++;
            num /= 10;
            digit++;
        }

        bool exist = false;
        for(int j=0; j<10; j++) {
            if(numbers[j] == digit-1) exist = true;
        }

        if(exist) inter_num++;
    }

    cout << inter_num;
    return 0;
}