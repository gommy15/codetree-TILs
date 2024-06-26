#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 8

int n;
bool visited[MAX_N+1];
vector<int> nums;

void Print() {
    for(int i=0; i<n; i++) {
        cout << nums[i] << ' ';
    }

    cout << '\n';
}

void FindNums(int cnt) {
    if(cnt == n) {
        Print();
        return;
    }

    for(int i=n; i>0; i--) {
        if(visited[i]) continue;

        nums.push_back(i);
        visited[i] = true;
        FindNums(cnt+1);
        nums.pop_back();
        visited[i] = false;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    FindNums(0);
    return 0;
}