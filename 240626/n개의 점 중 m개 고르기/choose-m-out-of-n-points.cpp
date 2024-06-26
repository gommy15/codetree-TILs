#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <utility>
#include <climits>
using namespace std;

int n, m;
vector<pair<int, int>> spots;
vector<pair<int, int>> selected_spot;

int ans = INT_MAX;

int Dist(pair<int, int> a, pair<int, int> b) {
    int ax, ay;
    tie(ax, ay) = a;

    int bx, by;
    tie(bx, by) = b;

    return (ax-bx)*(ax-bx) + (ay-by)*(ay-by);
}

int Calc() {
    int max_dist = -1;
    for(int i=0; i<selected_spot.size(); i++) {
        for(int j=i+1; j<selected_spot.size(); j++) {
            max_dist = max(max_dist, Dist(selected_spot[i], selected_spot[j]));
        }
    }

    return max_dist;
}

void FindMinDist(int cnt, int cur_idx) {
    if(cnt == m) {
        ans = min(ans, Calc());
        return;
    }

    for(int i=cur_idx; i<spots.size(); i++) {
        selected_spot.push_back(spots[i]);
        FindMinDist(cnt+1, i+1);
        selected_spot.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;
    
    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x>>y;
        spots.push_back(make_pair(x, y));
    }

    FindMinDist(0, 0);

    cout << ans;

    return 0;
}