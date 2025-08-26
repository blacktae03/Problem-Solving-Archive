#include <bits/stdc++.h>
using namespace std;

int N, K;
long long ans;
map<int, int> jwl; // jwl[V] = M
multiset<int> cap; // 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int M, V; cin >> M >> V;
        jwl[V] = M;
    }

    for (int i = 0; i < K; i++) {
        int C; cin >> C;
        cap.insert(C);
    }

    auto bag = cap.begin(); // 제일 낮은 거

    for (int i = 0; i < K && !jwl.empty(); i++) {
        auto j = prev(jwl.end());
        bool notInMyBag = false;
        while(j->second > *bag) {
            if (j == jwl.begin()) {
                notInMyBag = true;
                break;
            }
            j = prev(j);
        }
        
        if (!notInMyBag) {
            ans += j->first;
            jwl.erase(j);
        }

        bag = next(bag);
    }

    cout << ans;
}
// 가방의 C가 낮은 것부터 jwl의 V를 기준으로 내림차순으로 정렬 됐다고 할 때, 보석의 M이 가방보다 낮으면 답에 추가하기.
// NlgN까지는 가능한 문제