#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int n, m;
unordered_set<int> aseq;
vector<int> bseq;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    int num;
    while(n--) {
        cin >> num;
        aseq.insert(num);
    }

    cin >> m;
    while(m--) {
        cin >> num;
        bseq.push_back(num);
    }

    for(int num : bseq) {
        if(aseq.find(num) == aseq.end()) cout << 0 << '\n';
        else cout << 1 << '\n';
    }

    return 0;
}