// 시간초과 발생
#include <bits/stdc++.h>
using namespace std;
#define S first
#define E second

int N;
pair<int, int> T[200020];
vector<int> ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int s, e; cin >> s >> e;
        T[i] = {s, e};
    }

    sort(T, T+N);
    ans.push_back(T[0].E);

    while(true) {
        for (int i = 1; i < N; i++) {
            bool fit = 0;
    
            for (auto & e : ans) {
                if (T[i].S < e) continue;
                e = T[i].E;
                fit = 1;
                break;
            }
    
            if (!fit) ans.push_back(T[i].E);
        }
        
    }

    cout << ans.size();
}
// 일단 정렬을 해보자
// 1 5
// 2 3
// 5 7
// 8 10
// 8 11