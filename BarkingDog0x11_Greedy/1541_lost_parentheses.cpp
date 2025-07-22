#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string exp; cin >> exp;
    exp += '+'; // 마지막 예외처리를 피하기 위함.
    int sum = 0, ans = 0;
    bool inPrth = 0;

    // char test = '0'; // 48
    // char test = '+'; // 43
    // char test = '-'; // 45

    for (char n : exp) {
        if (n >= '0') {
            sum *= 10;
            sum += n - '0';
        }

        else {
            if (inPrth) ans -= sum;
            else ans += sum;

            if (n == '-') inPrth = 1;
            sum = 0;
        }        
    }

    cout << ans;
}
// 자 마이너스를 만나면 -를 만날 때 까지 다 괄호로 묶어버려야 해 그래야 최솟값이 나옴.