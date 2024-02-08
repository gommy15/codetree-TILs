#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
#define MAX_N 1000

int n, b;
int p[MAX_N], s[MAX_N];
pair<int, int> tmp[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>b;
    for(int i=0; i<n; i++) {
        cin >> p[i]>>s[i];
    }

    int max_stu =0;
    for(int i=0; i<n; i++) {
        int pri;
        
        for(int j=0; j<n; j++) {
            if(i==j) pri = p[j]/2;
            else pri = p[j];

            tmp[j] = make_pair(pri, s[j]);
        }

        sort(tmp, tmp+n);
        int stu = 0, budget = 0;
        for(int j=0; j<n; j++) {
            if(budget+tmp[j].first+tmp[j].second <= b) {
                stu++;
                budget += (tmp[j].first + tmp[j].second);
            } else
                break;
        }

        max_stu = max(max_stu, stu);
    }

    cout << max_stu;
    return 0;
}