#include <bits/stdc++.h>
using namespace std;

int t, n;
long long ans;
int nums[109];
bool mark[109];
vector<int> V;

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(mark+2, mark+109, 1);

    cin >> t;

    while (t--) {
        cin >> n;

        for (int i = 0; i < n; i++) cin >> nums[i];

        do {
            for (int i = 0; i < n; i++) {
                if (mark[i]) continue;
                V.push_back(nums[i]);
            }
            
            ans += gcd(V[0], V[1]);
            V.clear();
        } while(next_permutation(mark, mark+n));

        cout << ans << '\n';
        ans = 0;
    }
}