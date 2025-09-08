#include <bits/stdc++.h>
using namespace std;

int N, ans;
priority_queue<int> pq[200020];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int d, c; cin >> d >> c;
        pq[d].push(c);
        
    }

    int prob = 1;
    for (int i = 1; i <= N; i++) {
        prob = max(prob, i);
        while (pq[prob].empty() && prob < N) prob++;
        if (prob == N && pq[prob].empty()) break;
        ans += pq[prob].top();
        pq[prob].pop();
    }

    cout << ans;
}

// 데드라인이 k인건 pq[k]에다가 얻을 수 있는 컵라면 수 최대힙으로 넣고 다 더하면 될 거 같은데?? 뭐지;; 귀엽네 ㅋ
// 7
// 3 5
// 3 6
// 5 100
// 5 101
// 5 102
// 5 103
// 5 104
// 이렇게 들어오면?
// 5 5개 씹어먹어도 모자랄 판에 나는 3부터 먹고 있네.. 다시 짜보자 제한시간 2초라서 NlgN까지는 감당 가능.