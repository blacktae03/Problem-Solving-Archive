#include <bits/stdc++.h>
using namespace std;

int N;
pair<pair<int, int>, pair<int, int>> dt[100010];
vector<pair<pair<int, int>, pair<int, int>>> ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int sd1, ed1, sd2, ed2;
        cin >> sd1 >> ed1 >> sd2 >> ed2;

        dt[i].first = {sd1, ed1};
        dt[i].second = {sd2, ed2};
    }

    sort(dt, dt+N);
    dt[N] = {{12,31}, {12,31}};
    ans.push_back({{1,1}, {3, 1}});

    // for (int i = 0; i < N; i++) {
    //     cout << dt[i].first.first << ' ' << dt[i].first.second << ' ' << dt[i].second.first << ' ' << dt[i].second.second << '\n';
    // }

    pair<int, int> tdts, tdte;
    int aidx = 0, didx = 0;

    for (int i = 0; i <= N; i++) {
        if (dt[i].first.first >= 12) {
            ans.push_back(dt[didx]);
            break;
        }

        if (dt[i].first <= ans.back().second) didx = i;
        else {
            ans.push_back(dt[didx]);
            if (ans.back().second.first >= 12) break;

            if (dt[i].first <= ans.back().second) didx = i;
            else { didx = 0; break; }
        }
    }

    if (didx) cout << ans.size()-1;
    else cout << 0;

    for (auto p : ans) {
        cout << '\n' << p.first.first << ' ' << p.first.second << ' ' << p.second.first << ' ' << p.second.second;
    }
}
// 자 dt의 개화 날짜가 답의 낙화 날짜보다 작으면 일단 넣을지 말지 고민해야 함 (인덱스 저장)
// 자 그러다가 dt의 개화 날짜가 답의 낙화 날짜보다 크다!!!! 그러면 저장해놨던거 넣어.
// 