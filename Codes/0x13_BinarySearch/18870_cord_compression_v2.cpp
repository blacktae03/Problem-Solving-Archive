#include <bits/stdc++.h>
using namespace std;

int N, same;
vector<int> I, X;
int U[1000010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        I.push_back(tmp);
    } // 정렬할 벡터
    X = I; // 정렬하지 않을 벡터

    sort(I.begin(), I.end()); // NlgN
    // I.erase(unique(I.begin(), I.end()), I.end());
    
    int len = 0, prev = INT_MIN;
    for (auto t : I) {
        U[len] = t;
        if (t != prev) len++;
        prev = t;
    } // 20을 바꾼 방법. 구현력 기르기 연습임 그냥.

    // for (auto i : I) cout << i << ' ';
    // cout << '\n';
    // for (auto x : X) cout << x << ' ';

    for (auto x : X) cout << lower_bound(U, U+len, x) - U << ' ';
}