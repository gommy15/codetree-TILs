#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> seq;

void Print() {
    for(const auto& num : seq) {
        cout << num << ' ';
    }
    cout << '\n';
}

void MakeSeq(int idx) {
    if (idx == n) {
        Print();
        return;
    }

    for(int i=1; i<=k; i++) {
        seq.push_back(i);
        MakeSeq(idx+1);
        seq.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k>>n;

    MakeSeq(0);

    return 0;
}