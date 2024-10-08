#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int n, ans;
vector<pair<int, int>> lines, selec_l;

void FindMax(int cnt) {
    if(cnt == n) {
        ans = max(ans, (int)selec_l.size());
        return;
    }

    if(selec_l.size() == 0) {
        selec_l.push_back(lines[cnt]);
        FindMax(cnt+1);
        selec_l.pop_back();
    } else {
        int x1, x2;
        tie(ignore, x2) = selec_l.back();
        tie(x1, ignore) = lines[cnt];

        if(x2 < x1) {
            selec_l.push_back(lines[cnt]);
            FindMax(cnt+1);
            selec_l.pop_back();
        } else {
            FindMax(cnt+1);
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        int x1, x2;
        cin >> x1>>x2;
        lines.push_back(make_pair(x1, x2));
    }

    sort(lines.begin(), lines.end());

    FindMax(0);

    cout << ans;
    
    return 0;
}