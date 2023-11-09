#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_STU 1000

int n, b;
int p[MAX_STU];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>b;

    int num;
    for(int i=0; i<n; i++) {
        cin >> num;
        p[i] = -num;
    }

    sort(p, p+n);
    int max_stu = INT_MIN;
    for(int i=0; i<n; i++) {
        int sum = (-p[i])/2;
        int stu_num = 1;
        for(int j=i+1; j<n; j++) {
            sum += (-p[j]);
            if(sum > b) break;
            stu_num++;
        }
        max_stu = max(max_stu, stu_num);
    }

    cout << max_stu;
    return 0;
}