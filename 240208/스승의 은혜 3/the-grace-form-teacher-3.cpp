#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1000

int n, b;
int p[MAX_N], s[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>b;
    for(int i=0; i<n; i++) {
        cin >> p[i]>>s[i];
    }

    int max_stu =0;
    for(int i=0; i<n; i++) {
        int pri;
        int tmp[MAX_N] = {};
        for(int j=0; j<n; j++) {
            if(i==j) pri = p[j]/2;
            else pri = p[j];

            tmp[j] = pri+s[j];
        }

        sort(tmp, tmp+n);
        int stu = 0, budget = 0;
        for(int j=0; j<n; j++) {
            if(budget+tmp[j] <= b) {
                stu++;
                budget += tmp[j];
            } else
                break;
        }

        max_stu = max(max_stu, stu);
    }

    cout << max_stu;
    return 0;
}