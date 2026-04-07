// Task Scheduling Problem
#include <bits/stdc++.h>
using namespace std;

int N, ans;
pair<int, int> I[100010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> I[i].second >> I[i].first; // first가 종료 시간, second가 시작 시간

    sort(I, I+N);

    int en = 0;

    for (int i = 0; i < N; i++) {
        if (I[i].second < en) continue;
        en = I[i].first;
        ans++;
    }
    
    cout << ans;
}
// 바킹독 코드랑 거의 똑같음 second랑 first랑 자리 바꿔서 sort에 람다 안쓰고 처리하는 거 ㄹㅇ 구현력 하나는 봐줄만하네;;