#include <bits/stdc++.h>
using namespace std;

#define MAX_N 11

int n, m;
vector<pair<int, int>> lines;
vector<pair<int, int>> selc_lines;

int ans = INT_MAX;

bool Possible() {
    int num1[MAX_N], num2[MAX_N];
    for(int i=0; i<n; i++) {
        num1[i] = num2[i] = i;
    }

    for(int i=0; i<(int)lines.size(); i++) {
        int idx = lines[i].second;
        swap(num1[idx], num1[idx+1]);
    }

    for(int i=0; i<(int)selc_lines.size(); i++) {
        int idx = selc_lines[i].second;
        swap(num2[idx], num2[idx+1]);
    }

    for(int i=0; i<n; i++) {
        if(num1[i] != num2[i]) return false;
    }

    return true;
}

void FindMinLines(int cnt) {
    if(cnt == m) {
        if(Possible()) {
            ans = min(ans, (int)selc_lines.size());
        }
        return;
    }

    selc_lines.push_back(lines[cnt]);
    FindMinLines(cnt+1);
    selc_lines.pop_back();

    FindMinLines(cnt+1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n>>m;

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a>>b;

        lines.push_back({b, a-1});
    }

    sort(lines.begin(), lines.end());

    FindMinLines(0);

    cout << ans;
    return 0;
}