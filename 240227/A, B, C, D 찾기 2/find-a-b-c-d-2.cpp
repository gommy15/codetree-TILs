#include <iostream>
#include <algorithm>
using namespace std;
#define NUM_N 15

int random_num[NUM_N];

int main() {
    // 여기에 코드를 작성해주세요.
    for(int i=0; i<NUM_N; i++) {
        cin >> random_num[i];
    }

    sort(random_num, random_num+NUM_N);

    bool possible = true;
    for(int i=0; i<NUM_N; i++) {
        for(int j=i+1; j<NUM_N; j++) {
            for(int k=j+1; k<NUM_N; k++) {
                for(int l=k+1; l<NUM_N; l++){
                    possible = true;
                    int a = random_num[i], b = random_num[j], c = random_num[k], d = random_num[l];
                    int tmp[NUM_N] = {a, b, c, d, a+b, b+c, c+d, d+a, a+c, b+d, a+b+c, a+b+d, a+c+d, b+c+d, a+b+c+d};

                    sort(tmp, tmp+NUM_N);

                    for(int x=0; x<NUM_N; x++) {
                        if(random_num[x] != tmp[x]) possible = false;
                    }

                    if(possible) {
                        cout << a << ' ' << b << ' ' << c << ' ' << d;
                        break;
                    }
                }
                if(possible) break;
            }
            if(possible) break;
        }
        if(possible) break;
    }
    return 0;
}