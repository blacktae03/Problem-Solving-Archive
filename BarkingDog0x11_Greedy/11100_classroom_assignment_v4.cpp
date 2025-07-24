// 시간초과 발생. 끝나는 시간을 따로 저장해볼까..?
#include <bits/stdc++.h>
using namespace std;
#define E first
#define S second

int N;
pair<int, int> T[200020];
// vector<int> ans;
vector<int> V;
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
    ans++;
    V.push_back(T[0].E);

    for (int i = 1; i < N; i++) {
        if (T[i].S < V.front()) {
            ans++;
            V.push_back(T[i].E);
        }

        else {
            V.erase(V.begin());
            V.push_back(T[i].E);
        }
    }

    cout << ans;
}
// 내 예제는
// 1 9
// 2 3
// 3 6
// 4 7
// 6 10
// 7 9
// 일단 시작하는 시간 기준으로 정렬해보자
// 1 9
// 2 3
// 3 6
// 4 7
// 6 10
// 7 9
// 그러면 음..
// 시작하는 시간이 앞의 끝나는 시간보다 작으면 ans++
// 1 9 ans = 1 min = 9
// 2 3 ans = 2 min = 3
// 3 6 ans = 2 min = 6
// 4 7 ans = 3 min = 6
// 6 10 ans = 3 min = 10 흠 min이 7이 되게 하려면 어떡해야할까...

// 끝나는 시간 기준으로 정렬해보자
// 2 3
// 3 6
// 4 7
// 1 9
// 7 9
// 6 10
// 시작하는 시간이 앞의 끝나는 시간보다 작으면 ans++
// 2 3 ans = 1, min = 3
// 3 6 ans = 1, min = 6
// 4 7 ans = 2, min = 6(그대로)
// 1 9 ans = 3, min = 6(그대로)
// 7 9 ans = 3, min = 7로 가야함 여기서 큐로 가야된다고 생각했는데 안되네...
// 흠...