// 시간초과 발생. 끝나는 시간을 따로 저장해볼까..?
#include <bits/stdc++.h>
using namespace std;
#define E first
#define S second

int N;
pair<int, int> T[200020];
// vector<int> ans;
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int s, e; cin >> s >> e;
        T[i] = {e, s};
    }

    sort(T, T+N);
    int end = T[0].E;
    ans++;

    for (int i = 1; i < N; i++) {
        if (T[i].S < end) {
            ans++;
            end = 
        }
    }

    cout << ans;
}
// 일단 정렬을 해보자
// 1 5
// 2 3
// 5 7
// 8 10
// 8 11