#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int n, ans;
vector<pair<int, int>> segments;
vector<pair<int, int>> selected_segs;

bool Overlapped(pair<int, int> seg1, pair<int, int> seg2) {
    int a1, a2;
    tie(a1, a2) = seg1;

    int b1, b2;
    tie(b1, b2) = seg2;

    return (a1<=b1 && b1<=a2) || (a1<=b2 && b2<=a2) || (b1<=a1 && a1 <=b2) || (b1<=a2 && a2<=b2);
}

bool Possible(){
    for(int i=0; i<(int)selected_segs.size(); i++) {
        for(int j=i+1; j<(int)selected_segs.size(); j++) {
            if(Overlapped(selected_segs[i], selected_segs[j]))
                return false;
        }
    }

    return true;
}

void FindMaxLine(int cnt) {
    if(cnt == n) {
        if(Possible())
            ans = max(ans, (int)selected_segs.size());
        return;
    }

    selected_segs.push_back(segments[cnt]);
    FindMaxLine(cnt +1);
    selected_segs.pop_back();

    FindMaxLine(cnt +1);
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x>>y;
        segments.push_back(make_pair(x, y));
    }

    FindMaxLine(0);

    cout << ans;
    return 0;
}