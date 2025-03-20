#include <bits/stdc++.h>
using namespace std;

int n, ans;
vector<pair<int, int>> line;
vector<pair<int, int>> cho;

bool Check() {

    for(int i=1; i<(int)cho.size(); i++) {
        int x, y;
        tie(x, y) = cho[i-1];

        int x2, y2;
        tie(x2, y2) = cho[i];

        if(!(y < x2)) return false;
    }

    return true;
}

void FindMaxLine(int idx) {
    if(idx == (int)line.size()) {
        if(Check()) {
            ans = max(ans, (int)cho.size());
        }
        return;
    }

    cho.push_back(line[idx]);
    FindMaxLine(idx + 1);
    cho.pop_back();

    FindMaxLine(idx+1);
}

int main() {
    cin >> n;

    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x>>y;
        line.push_back({x, y});
    }

    sort(line.begin(), line.end());
    FindMaxLine(0);

    cout << ans;
    return 0;
}