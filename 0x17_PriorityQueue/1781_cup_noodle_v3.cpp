#include <bits/stdc++.h>
using namespace std;

int N, cap, sum;
priority_queue<int> pq[200020];
priority_queue<int, vector<int>, greater<>> ans;
int cnt[200020];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int d, c;
        cin >> d >> c;

        pq[d].push(c);
    }

    int eaten = 0;

    for (int i = 1; i <= N; i++) {
        if (pq[i].empty()) continue;

        while(ans.size() < i || pq[i].top() > ans.top()) {
            ans.push(pq[i].top());
            pq[i].pop();
            if (ans.size() > i) ans.pop();
            if (pq[i].empty()) break;
        }
    }
    // O(N^2)처럼 보일 수 있지만 O(N)임.
    // 왜냐하면 for 문이 한 번 돌 때마다 while문이 도는 횟수는 최대 pq[i].size()임.
    // Ai = pq[i].size()라고 할 때, Sigma A (i : 1~N) = N이므로 while문이 다 돌아도 N번임.
    // 심지어 pq[i].top()이 ans.top()보다 작으면 while문이 돌지도 않음.

    while (!ans.empty()) {
        sum += ans.top();
        ans.pop();
    }

    cout << sum;
}
