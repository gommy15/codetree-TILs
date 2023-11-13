#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

int n, m, d, s;
tuple<int, int, int> recode[1000];
pair<int, int> sick[50];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m>>d>>s;

    int p, ms, t;
    for(int i=0; i<d; i++) {
        cin >> p>>ms>>t;
        recode[i] = make_tuple(p, ms, t);
    }

    for(int i=0; i<s; i++) {
        cin >>p>>t;
        sick[i] = make_pair(p, t);
    }

    int cnt = 0;
    for(int i=1; i<=m; i++) {
        int time[51] = {};
        for(int j=0; j<d; j++) {
            if(get<1>(recode[j]) != i) continue;
            
            p = get<0>(recode[j]);
            if(time[p] == 0) time[p] = get<2>(recode[j]);
            else if (time[p] > get<2>(recode[j])) time[p] = get<2>(recode[j]);
        }

        bool possible = true;
        for(int j=0; j<s; j++) {
            p = sick[j].first;
            if(time[p] == 0) possible = false;
            if(time[p] >= sick[j].second) possible = false;
        }

        int pill = 0;
        if(possible) {
            for(int j=1; j<=n; j++) {
                if(time[j] != 0) pill++;
            }
        }

        cnt = max(cnt, pill);
    }
    cout << cnt;

    return 0;
}