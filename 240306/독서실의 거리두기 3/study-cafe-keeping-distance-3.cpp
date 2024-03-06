#include <iostream>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;
#define MAX_N 1000

int n;
int seat[MAX_N];
string str;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>str;
    int tmp[MAX_N] = {};
    int cnt = 0;
    for(int i=0; i<n; i++) {
        seat[i] = str[i]-'0';
        if(seat[i] == 1) tmp[cnt++] = i;
    }

    int x = tmp[0], y = tmp[1];
    for(int i=1; i<cnt-1; i++) {
        if((y-x) < (tmp[i+1]-tmp[i])) {
            x = tmp[i];
            y = tmp[i+1];
        }
    }

    seat[(x+y)/2] = 1;
    int len = 1;
    int min_len = INT_MAX;
    for(int i=0; i<n; i++) {
        if(seat[i] == 1) {
            for(int j=i+1;j<n; j++) {
                if(seat[j] == 1) {
                    min_len = min(min_len, j-i);
                    break;
                }
            }
        }
    }
    
    // for(int i=0; i<n; i++) {
    //     // cout << seat[i];
    //     if(i == 0 && seat[i] == 1) continue;
    //     if(seat[i] == 1) {
    //         min_len = min(min_len, len);
    //         len = 1;
    //     } else 
    //         len++;
    // }
    // cout << '\n';
    cout << min_len;
    return 0;
}