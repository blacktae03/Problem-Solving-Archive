#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long a, b, tmp;
    cin >> a >> b;
    if (a == b) {
        cout << 0;
        return 0;
    }
    if (a > b) {
        tmp = a;
        a = b;
        b = tmp;
        //아니 swap 내가 정의 안해도 그냥 쓸 수 있노 swap(a,b); 가능
    }
    cout << b - a - 1 << '\n';
    for (long long i = a+1; i < b; i++) {
        cout << i << ' ';
    }
}