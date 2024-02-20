#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define MAX_N 100

int n;
string str;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>str;

    int ans = 1;
    // 길이를 늘려가는 기준 값 결정
    for(int i=1; i<n; i++) {
        bool twice = false;

        // 비교하는 시작점 두 곳을 설정
        for(int j=0; j<=n-i; j++) {
            for(int k=j+1; k<=n-i; k++) {
                bool issame = true;

                // 비교하는 길이만큼 각 시작점부터 비교
                for(int l=0; l<i; l++) {
                    // 비교하는 값이 다르다면 2회 이상 반복되는 문자열이 없음을 의미
                    if(str[j+l] != str[k+l]) issame = false;
                }

                if(issame) twice = true;
            }
        }
        // 2회 이상 반복되는 문자열이 있다면 그 길이가 i+1이 됨
        if(twice) ans = i+1;
        // 처음부터 없다면 2회 이상 반복되는 문자열의 최소 길이가 1이 됨
        else break;
    }

    cout << ans;


    return 0;
}