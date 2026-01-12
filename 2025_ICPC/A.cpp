#include <bits/stdc++.h>
using namespace std;

int N = 3000, ans;
vector<int> v1, v2;

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    // cin >> N;

    for (int i = 0; i < 3000; i++) {
        // int tmp;
        // cin >> tmp;
        v1.push_back(i+1);
    }
    for (int i = 0; i < 3000; i++) {
        // int tmp;
        // cin >> tmp;
        v2.push_back(N-i);
    }

    int idx1, idx2;
    int st = 0, en = N;
    // idx1 = *min_element(v1.begin()+0, v1.begin()+4);
    // cout << idx1;

    int cnt = 0;
    while(st < N) {
        idx1 = min_element(v1.begin()+st, v1.begin()+en) - v1.begin();
        idx2 = min_element(v2.begin()+st, v2.begin()+en) - v2.begin();

        if (idx1 != idx2) en = max(idx1, idx2);
        else {
            st = en;
            en = N;
            ans++;
            // cout << st << '\n';
        }
        cout << cnt++ << '\n';
    }

    cout << ans << '\n';
    // cout << cnt;
}
