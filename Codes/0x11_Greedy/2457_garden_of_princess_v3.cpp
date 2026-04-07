#include <bits/stdc++.h>
using namespace std;

int N;
pair<pair<int, int>, pair<int, int>> dt[100010];
pair<pair<int, int>, pair<int, int>> ans[100010];

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
    // dt[N] = {{12,31}, {12,31}};
    ans[0] = {{1,1}, {3, 1}};

    // for (int i = 0; i < N; i++) {
    //     cout << dt[i].first.first << ' ' << dt[i].first.second << ' ' << dt[i].second.first << ' ' << dt[i].second.second << '\n';
    // }

    pair<int, int> tdts, tdte;
    int aidx = 0, didx = 0;

    for (int i = 0; i < N; i++) {
        // if (dt[i].first.first >= 12) {
        //     ans.push_back(dt[didx]);
        //     break;
        // }

        if (dt[i].first <= ans[aidx].second) {
            // cout << aidx+1 << "->" << i << "change\n";
            if (dt[i].second >= ans[aidx+1].second) ans[aidx+1] = dt[i];
            if (ans[aidx+1].second.first >= 12) break;
        }

        else {
            aidx++;

            if (dt[i].first <= ans[aidx].second) {
                if (dt[i].second >= ans[aidx+1].second) ans[aidx+1] = dt[i];
                if (ans[aidx+1].second.first >= 12) break;
            }

            else {
                aidx = -1;
                break;
            }
        }
    }

    if (ans[aidx+1].second.first < 12) cout << 0;
    else cout << aidx+1;

    // for (auto p : ans) {
    //     if (p.first.first == 0) break;
    //     cout << '\n' << p.first.first << ' ' << p.first.second << ' ' << p.second.first << ' ' << p.second.second;
    // }
}
// 자 dt의 개화 날짜가 답의 마지막(aidx) 낙화 날짜보다 작거나 같으면 답의 aidx+1에 일단 넣는다. (aidx는 그대로) 근데 이때 aidx+1의 꽃보다 낙화가 빠르다면 굳이 넣을 필요가 없어.
// 다음 dt의 개화 날짜가 답의 낙화 날짜보다 작거나 같으면 교체한다. 이 때 교체한 꽃의 낙화 시점이 12월 이후이면 break (정렬했으므로 시작점이 지금 aidx에 들어간 답보다 뒤에 시작함)
// 다음 dt의 개화 날짜가 답의 낙화 날짜보다 크면 aidx++ 해서 똑같은 짓을 다시 한다. 답의 마지막 꽃 낙화 날짜보다 dt의 개화 날짜가 더 앞이면 그 뒤에 그 꽃을 추가하고 아니면 탈출한다.
// 탈출하는 이유는 어차피 그 이후의 꽃도 개화 시기가 더 늦거나 같으므로 꽃이 계속 피어있을 수 없기 때문. ex) 3 5 8 10의 뒤에 오는 꽃은 무조건 개화시기는 3 5 이후이고, 낙화시기 또한 8 10 이후인 경우이다.
// 