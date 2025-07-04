#include <bits/stdc++.h>
using namespace std;

long long val = 1;
long long a, b, c;
stack<bool> S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;

    // val %= c;
    long long tb = b;

    while(tb != 0) {
        if (tb % 2) {S.push(1); tb--;}
        else S.push(0);
        tb /= 2;
    }
    
    while(!S.empty()) {
        bool cur = S.top(); S.pop();

        val = val * val % c;
        // val *= val % c;
        // val %= c;
        if (cur) val = val * a % c;
        // if (cur) {
        //     val *= a % c;
        //     val %= c;
        // } 주석으로 대체 가능
    }

    cout << val;
}
// ex) b = 25(10) == 11001(2)이라고 할 때
// a 곱하고(1) 나 자신 곱하고(2) a 곱하고(3) 나 자신 곱하고(6) 나 자신 곱하고(12) 나 자신 곱하고(24) a 곱하면(25) 되잖아
// 14 == 10110(2)