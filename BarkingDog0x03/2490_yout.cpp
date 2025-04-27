#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int y, o,u,t;

    for (int i = 0; i < 3; i++) {
        cin >> y >> o >> u >> t;

        int res = y+o+u+t;

        if(res == 4) cout << "E\n";
        else if(res == 3) cout << "A\n";
        else if(res == 2) cout << "B\n";
        else if(res == 1) cout << "C\n";
        else if(res == 0) cout << "D\n";
    }
}