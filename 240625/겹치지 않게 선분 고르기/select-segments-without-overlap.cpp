#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

#define MAX_N 15

int n;
pair<int, int> segments[MAX_N];

int ans;
vector<pair<int, int>> selected_segs;

bool Overlapped(pair<int, int> seg1, pair<int, int> seg2) {
    int a1, a2;
    tie(a1, a2) = seg1;

    int b1, b2;
    tie(b1, b2) = seg2;

    return (a1 <= b1 && b1 <= a2) || (a1 <= b2 && b2 <= a2) || (b1 <= a1 && a1 <= b2) || (b1 <= a2 && a2 <= b2);
}

bool Possible() {
    for(int i=0; i<selected_segs.size(); i++) {
        for(int j=i+1; j<selected_segs.size(); j++) {
            if(Overlapped(selected_segs[i], selected_segs[j]))
                return false;
        }
    }

    return true;
}

void FindMaxSegments(int cnt) {
    if(cnt == n) {
        if(Possible())
            ans = max(ans, (int)selected_segs.size());
        return;
    }

    selected_segs.push_back(segments[cnt]);
    FindMaxSegments(cnt + 1);
    selected_segs.pop_back();

    FindMaxSegments(cnt +1);
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        int x1, x2;
        cin >> x1>>x2;
        segments[i] = make_pair(x1, x2);
    }

    FindMaxSegments(0);

    cout << ans;
    return 0;
}