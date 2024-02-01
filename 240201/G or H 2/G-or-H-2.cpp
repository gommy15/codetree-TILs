#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
#define MAX_N 100

int n;
pair<int, char> people[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    int idx; char alpa;
    for(int i=0; i<n; i++) {
        cin >> idx>>alpa;
        people[i] = make_pair(idx, alpa);
    }

    sort(people, people+n);

    int max_size = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            int cnt_g = 0, cnt_h = 0;
            for(int k=i; k<=j; k++) {
                if(people[k].second == 'G') cnt_g++;
                else cnt_h++;
            }

            if(cnt_g == cnt_h) {
                max_size = max(max_size, (people[j].first - people[i].first));
            }
        }
    }

    cout << max_size;
    return 0;
}