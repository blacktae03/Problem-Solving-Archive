#include <bits/stdc++.h>
using namespace std;

string G, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> G;

    if (G[0] == 'F') {
        cout << "0.0";
        return 0;
    }

    switch(G[0]) {
        case 'A' :
            ans += '4';
            break;
        
        case 'B' :
            ans += '3';
            break;

        case 'C' :
            ans += '2';
            break;

        case 'D' :
            ans += '1';
            break;
    }
    
    ans += '.';
    
    switch(G[1]) {
        case '+' :
            ans += '3';
            break;
        
        case '0' :
            ans += '0';
            break;

        case '-' :
            ans[0] -= 1;
            ans += '7';
            break;
    }

    cout << ans;
}