#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <climits>
using namespace std;
#define MAX_N 11

int n, m;
vector<pair<int, int>> lines;
vector<pair<int, int>> selected_lines;

int ans = INT_MAX;

int org_seq[MAX_N];

bool Check() {
    int seq[MAX_N];
    for(int i=0; i<n; i++) {
        seq[i] = i;
    }

    for(int i=0; i<(int)selected_lines.size(); i++) {
        int a;
        tie(ignore, a) = selected_lines[i];

        int tmp = seq[a];
        seq[a] = seq[a+1];
        seq[a+1] = tmp;
    }

    for(int i=0; i<n; i++) {
        if(org_seq[i] != seq[i])
            return false;
    }
    return true;
}

void FindMinLines(int cnt) {
    if(cnt == m) {
        if(Check()) {
            ans = min(ans, (int)selected_lines.size());
        }
        return;
    }

    selected_lines.push_back(lines[cnt]);
    FindMinLines(cnt+1);
    selected_lines.pop_back();

    FindMinLines(cnt+1);
}


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a>>b;
        lines.push_back(make_pair(b, a-1));
    }

    sort(lines.begin(), lines.end());

    for(int i=0; i<n; i++) {
        org_seq[i] = i;
    }

    for(int i=0; i<m; i++) {
        int a;
        tie(ignore, a) = lines[i];

        int tmp = org_seq[a];
        org_seq[a] = org_seq[a+1];
        org_seq[a+1] = tmp;
    }

    FindMinLines(0);

    cout << ans;
    return 0;
}