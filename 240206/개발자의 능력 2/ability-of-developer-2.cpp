#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int dev[6];

int main() {
    // 여기에 코드를 작성해주세요.
    int total_sum = 0;
    for(int i=0; i<6; i++) {
        cin >> dev[i];
        total_sum += dev[i];
    }

    int min_diff = INT_MAX;
    for(int i=0; i<6; i++) {
        for(int j=0; j<6; j++) {
            if(i == j) continue;
            for(int k=0; k<6; k++) {
                if(k==i || k==j) continue;
                for(int l=0; l<6; l++) {
                    if(l==i || l==j || l==k) continue;
                    int tm1 = dev[i] + dev[j];
                    int tm2 = dev[j] + dev[k];
                    int tm3 = total_sum - tm1 - tm2;

                    int max_sum = max(tm1, tm2);
                    max_sum = max(max_sum, tm3);

                    int min_sum = min(tm1, tm2);
                    min_sum = min(min_sum, tm3);

                    min_diff = min(min_diff, (max_sum-min_sum));
                }
            }
        }
    }

    cout << min_diff;
    return 0;
}