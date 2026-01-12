#include <bits/stdc++.h>
using namespace std;

int N;
map<int, int> M;
multiset<int> MS;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int h, k;
        cin >> h >> k;
        M[h] = k;
    }

    auto it = M.end();
    // int i = 0;
    MS.insert(0);

    while (it != M.begin()) {
        it = prev(it); //end의 prev부터 이 반복문을 실행하면 이미 들어간 학생들은 무조건 지금 나보다 키가 큰 학생들이다.
        
        auto where = MS.lower_bound(it->second); // 최소 등수가 k일 때, k 이상인 가장 작은 iterator를 찾는다.
        if (where == MS.begin()) MS.insert(1); // 키가 본인보다 큰 사람이 k보다 작은 팀이 없다는 뜻이므로 1명이 포함된 (자기 자신만 들어가 있는) 팀을 하나 더 만든다.
        else {
            where = prev(where); // 키가 큰 사람이 k보다 작으면서 가장 많은 팀에 들어가야 하므로, prev 한다.
            MS.insert(*where+1); // 팀에 사람 추가.
            MS.erase(where);
        }
    }

    cout << MS.size();
}