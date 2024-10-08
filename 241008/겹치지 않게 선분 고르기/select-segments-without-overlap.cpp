#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#define MAX_N 15

int n;
pair<int, int> segments[MAX_N];

int ans;
vector<pair<int, int>> selected;

bool Overlapped(pair<int, int> seg1, pair<int, int> seg2) {
    int ax1, ax2;
    tie(ax1, ax2) = seg1;

    int bx1, bx2;
    tie(bx1, bx2) = seg2;

    return (ax1 <= bx1 && bx1 <= ax2) || (ax1 <= bx2 && bx2 <= ax2) || (bx1 <= ax1 && ax1 <= bx2) || (bx1 <= ax2 && ax2 <= bx2);
}

bool Possible() {
    for(int i=0; i<selected.size(); i++) {
        for(int j=i+1; j<selected.size(); j++) {
            if(Overlapped(selected[i], selected[j]))
                return false;
        }
    }
    return true;
}

void FindMaxSegments(int cnt) {
    if(cnt == n) {
        if(Possible()) {
            ans = max(ans, (int)selected.size());
        }
        return;
    }

    selected.push_back(segments[cnt]);
    FindMaxSegments(cnt+1);
    selected.pop_back();

    FindMaxSegments(cnt+1);
}

int main() {
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