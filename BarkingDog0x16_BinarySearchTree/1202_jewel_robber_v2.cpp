#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, K;
ll ans;
map<ll, ll> jwl; // jwl[V] = M
multiset<ll> cap; // 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 0; i < N; i++) { // NlgN
        ll M, V; cin >> M >> V;
        jwl[V] = M;
    }

    for (int i = 0; i < K; i++) { // KlgK
        ll C; cin >> C;
        cap.insert(C);
    }

    auto j = prev(jwl.end());

    for (int i = 0; i < N && !cap.empty(); i++) {
        auto bag = cap.lower_bound(j->second);

        // bool notInMyBag = false;
        // while(j->second > *bag && bag != cap.end()) bag = next(bag); // NlgN
        
        if (bag != cap.end()) {
            ans += j->first;
            cap.erase(bag);
        }

        j = prev(j);
    }

    cout << ans;
}
// 가방의 C가 낮은 것부터 jwl의 V를 기준으로 내림차순으로 정렬 됐다고 할 때, 보석의 M이 가방보다 낮으면 답에 추가하기.
// NlgN까지는 가능한 문제