#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> seq;

void Print() {
    for(int i=0; i<(int)seq.size(); i++) {
        cout << seq[i] << ' ';
    }
    cout << '\n';
}

void Sum(int cnt) {
    if(cnt == n) {
        Print();
        return;
    }

    for(int i=1; i<=k; i++) {
        seq.push_back(i);
        Sum(cnt+1);
        seq.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> k>>n;

    Sum(0);
    return 0;
}