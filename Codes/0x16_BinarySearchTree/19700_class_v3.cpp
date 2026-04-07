#include <bits/stdc++.h>
using namespace std;

int N;
// map<int, int> M; 풀고나서 보니까 굳이 이거 맵 쓸 필요 없는 거 같아서 수정하기.
// sort를 한 번 해줘야 한다는 단점이 있지만 이게 메모리랑 시간 둘 다 단축함.
// 난이도 기여를 한 번 보니, MS의 값을 음수로 저장해서 upper_bound를 쓰는 방법도 있다고 한다.
// 오 그러네 k값이 3인 친구가 있고 -3, -3, -1, -1 일 때, -1의 맨 앞에 iter가 위치하겠네
// 그 값이 end면 없는 거고. 이거 v4로 코드 짜고 자야겠다
vector<pair<int, int>> V;
multiset<int> MS;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int h, k;
        cin >> h >> k;
        V.push_back({h, k});
    }

    sort(V.begin(), V.end(), greater<>()); // greater가 내림차순, less가 오름차순
    // int i = 0;
    MS.insert(0);

    for (auto p : V) {
        auto where = MS.lower_bound(p.second); // 최소 등수가 k일 때, k 이상인 가장 작은 iterator를 찾는다.
        if (where == MS.begin()) MS.insert(1); // 키가 본인보다 큰 사람이 k보다 작은 팀이 없다는 뜻이므로 1명이 포함된 (자기 자신만 들어가 있는) 팀을 하나 더 만든다.
        else {
            where = prev(where); // 키가 큰 사람이 k보다 작으면서 가장 많은 팀에 들어가야 하므로, prev 한다.
            MS.insert(*where+1); // 팀에 사람 추가.
            MS.erase(where);
        }
    }

    cout << MS.size();
}