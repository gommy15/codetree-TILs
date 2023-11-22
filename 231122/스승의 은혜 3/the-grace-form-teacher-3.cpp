#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_STU 1000

int n, b;
pair<int, int> student[MAX_STU];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>b;
    int price, deliv;
    for(int i=0; i<n; i++) {
        cin >> price>>deliv;
        student[i] = make_pair(price, deliv);
    }

    int max_stunum = INT_MIN;

    for(int i = 0; i < n; i++) {
        int tmp[MAX_STU] = {};
        for(int j = 0; j < n; j++) {
            price = student[j].first;
            deliv = student[j].second;
            if(i == j) price = price/2;

            tmp[j] = price + deliv;
        }

        sort(tmp, tmp + n);

        int stu_num = 0;
        int cnt = 0;

        for(int j = 0; j < n; j++) {
            if(cnt + tmp[j] > b)
                break;
            cnt += tmp[j];
            stu_num++;
        }

        max_stunum = max(max_stunum, stu_num);
    }

    cout << max_stunum;
    return 0;
}