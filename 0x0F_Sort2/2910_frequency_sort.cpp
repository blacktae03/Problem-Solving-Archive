#include <bits/stdc++.h>
using namespace std;

int N, C;
vector<pair<int, int>> V;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> C;

    while(N--) {
        int tmp;
        bool found = 0;
        cin >> tmp;

        for (auto & p : V) if (p.first == tmp) {p.second++; found = 1;} // 조건이나 반복문 뒤에 오는 실행문 1줄이면 그냥 붙여서 써도 되네.

        if (!found) V.push_back({tmp, 1});
    }

    stable_sort(V.begin(), V.end(), [](const pair<int, int> & a, const pair<int, int> & b) {
        return a.second > b.second;
    });

    for (auto p : V) for (int i = 0; i < p.second; i++) cout << p.first << ' '; // 이중반복문 붙여써도 잘 되네 ㅎㅎ
}

// 벡터에 빈도수랑 숫자 pair로 push_back 계속 하고 stable_sort 하면 될 거 같음.