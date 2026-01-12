#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.setf(ios::right);
    
    int N;

    cin >> N;

    string s = "";

    for (int i = N; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            s+='*';
        }
        cout << setw(N) << s << '\n';
        s = "";
    }
}