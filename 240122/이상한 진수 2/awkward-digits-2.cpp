#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

string bin;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> bin;

    int max_num = INT_MIN;

    for(int i=0; i<bin.size(); i++) {
        int num = 0;
        for(int j=0; j<bin.size(); j++) {
            if(i == j) {
                if(bin[i] == '1') num *= 2;
                else num = num*2+1;
            } else {
                num = num*2 + (bin[j]-'0');
            }
        }
        max_num = max(max_num, num);
    }

    cout << max_num;
    return 0;
}