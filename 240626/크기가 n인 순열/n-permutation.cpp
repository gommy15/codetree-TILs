#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 8

int n;
vector<int> nums;
bool visited[MAX_N+1];

void Print() {
    for(int i=0; i<n; i++) {
        cout<< nums[i] << ' ';
    }

    cout << '\n';
}

void FindNum(int cnt) {
    if(cnt == n) {
        Print();
        return;
    }

    for(int i=1; i<=n; i++) {
        if(visited[i]) continue;

        nums.push_back(i);
        visited[i] = true;
        FindNum(cnt+1);
        nums.pop_back();
        visited[i] = false;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    FindNum(0);
    return 0;
}