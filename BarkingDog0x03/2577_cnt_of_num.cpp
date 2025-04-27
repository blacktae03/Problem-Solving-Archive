#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, mul;
    int num[10] = {0,};

    cin >> A >> B >> C;

    mul = A*B*C;

    while(mul != 0) {
        num[mul%10]++;
        mul/=10;
    }

    for (auto n : num) cout << n << "\n";
}