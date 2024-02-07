#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1000

int n, b;
int p[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> b;
    // int pres;
    for(int i=0; i<n; i++) {
        cin >> p[i];
    }

    int max_student = 0;
    //반값을 적용할 학생 선택
    for(int i=0; i<n; i++) {
        int tmp[MAX_N] = {};

        for(int j=0; j<n; j++) {
            // 현재 for문 돌고 있는 문자가 무엇인지 착각하지 말기!!!
            if(i==j) tmp[j] = (p[j]/2);
            else tmp[j] = p[j];
        }
        // 가장 예산이 작은 학생부터 채우는 것이 가장 많은 학생에게 선물을 줄 수 있는 방법임!
        sort(tmp, tmp+n);

        int budget = 0;
        int student = 0;
        
        for(int j=0; j<n; j++) {
            // if(budget + tmp[j] > b) break;

            // budget += tmp[j];
            // student++;

            budget += tmp[j];

            if(budget <= b) student++;
            else break;
        }

        max_student = max(max_student, student);
    }

    cout << max_student;
    return 0;
}