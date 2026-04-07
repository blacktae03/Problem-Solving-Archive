#include <bits/stdc++.h>
using namespace std;

int A, B, V, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B >> V;

    V -= A;
    ans++;

    if (V > 0) {
        ans += V / (A-B);
        ans += V % (A-B) ? 1 : 0;
    }
    
    cout << ans;
}