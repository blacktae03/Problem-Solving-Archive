#include <bits/stdc++.h>
using namespace std;

int N, A, B;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    while(N--) {
        cin >> A >> B;

        int ans = B - A;

        switch(ans) {
            case 1 :
                ans = 1;
                break;
            
            case 2 :
                ans = 2;
                break;

            default :
                ans = (ans + 3) / 2;
        }

        cout << ans << '\n';
    }


}