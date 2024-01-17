#include <iostream>
using namespace std;
#define MAX_N 100

int n, m, k;
int student[MAX_N+1];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m>>k;

    int stu_num;
    int first_stu = -1;
    for(int i=0; i<m; i++) {
        cin >> stu_num;
        student[stu_num]++;

        if(student[stu_num] >= k) {
            first_stu = stu_num;
            break;
        }
        // for(int j=1; j<=n; j++) {
        //     if(student[j] >= k) {
        //         first_stu = j;
        //         break;
        //     }
        // }
        // if(first_stu != -1) break;
    }

    cout << first_stu;
    return 0;
}