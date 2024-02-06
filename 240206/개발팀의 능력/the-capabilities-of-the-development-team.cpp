#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int dev[5];

int main() {
    // 여기에 코드를 작성해주세요.
    int total_sum = 0;
    for(int i=0; i<5; i++) {
        cin >> dev[i];
        total_sum += dev[i];
    }

    int min_diff = INT_MAX;
    bool exist = false;
    for(int i=0; i<5; i++) {
        for(int j=i+1; j<5; j++) {
            for(int k=0; k<5; k++) {
                if(k==i || k==j) continue;
                for(int l=k+1; l<5; l++) {
                    if(l==i || l==j) continue;

                    int tm1 = dev[i]+dev[j];
                    int tm2 = dev[k]+dev[l];
                    int tm3 = total_sum - tm1 - tm2;
                    
                    if(tm1 == tm2 || tm2 == tm3 || tm3 == tm1) continue;
                    else exist = true;
                    int max_sum = max(tm1, tm2);
                    max_sum = max(max_sum, tm3);
                    int min_sum = min(tm1, tm2);
                    min_sum = min(min_sum, tm3);

                    min_diff = min(min_diff, (max_sum-min_sum));
                }
            }
        }
    }

    if(exist) cout << min_diff;
    else cout << -1;
    return 0;
}