#include <iostream>
using namespace std;
#define MAX_DIGIT 7

int x, y;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> x>>y;
    
    int cnt = 0;
    for(int i=x; i<=y; i++) {
        int num = i;
        int digit_num = 0;
        int number[MAX_DIGIT] = {}, rev_number[MAX_DIGIT] = {};
        
        while(num) {
            number[digit_num++] = num%10;
            num /= 10;
        }

        for(int j=0; j<digit_num; j++) {
            rev_number[j] = number[digit_num-j-1];
            // cout << rev_number[j] << ' ' << number[digit_numj] << '\n';
        }

        bool exist = true;
        for(int j=0; j<digit_num; j++) {
            // cout << number[j] << ' ' << rev_number[digit_num-1-j] << '\n';
            if(number[j] != rev_number[j]) {
                exist = false;
                break;
            }
        }

        if(exist) cnt++;
    }

    cout << cnt;
    return 0;
}