#include <iostream>
#include <algorithm>
#include <tuple>
#include <utility>
using namespace std;
#define MAX_D 1000
#define MAX_SN 50

int n, m, d, s;
tuple<int, int, int> history[MAX_D];
pair<int, int> sick[MAX_SN];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m>>d>>s;

    int dp, dm, dt;
    for(int i=0; i<d; i++) {
        cin >> dp>>dm>>dt;
        history[i] = make_tuple(dp, dm, dt);
    }

    int sp, st;
    for(int i=0; i<s; i++) {
        cin >>sp>>st;
        sick[i] = make_pair(sp, st);
    }

    int max_pill = 0;
    // 치즈 별로 상한 치즈였는지 확인
    for(int i=1; i<=m; i++) {
        // 해당하는 치즈를 먹은 사람들을 확인하는 타임라인 작성
        int time[MAX_SN+1] = {};

        for(int j=0; j<d; j++) {
            tie(dp, dm, dt) = history[j];
            if(dm != i) continue;
            
            // 처음 해당 치즈를 먹었거나 더 빨리 먹은 시간이 나온다면 타임라인 갱신
            if(time[dp] == 0) time[dp] = dt;
            else if (time[dp] > dt) time[dp] = dt;
        }

        // 해당 치즈를 먹은 사람이 아픈 시간과 비교하여 상한 치즈인지 확인
        bool possible = true;
        // 치즈가 상할 가능성이 있으면 true
        for(int j=0; j<s; j++) {
            sp = sick[j].first;
            st = sick[j].second;

            // 아프지 않았거나 먹기 전에 아팠다면 (먹은 후 1초 뒤에 반응이 오기 때문에 먹었을 때도 비교)
            if(time[sp] == 0) possible = false;
            else if (time[sp] >= st) possible = false;
        }

        int pill = 0;
        // 상한 치즈라면 한 번이라도 먹은 사람이면 약이 필요함
        if(possible) {
            for(int j=1; j<=n; j++) {
                if(time[j] != 0) pill++;
            }
        }

        max_pill = max(max_pill, pill);
    }

    cout << max_pill;
    return 0;
}