#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[3] = {0,0,0};
    fill(a+1, a+1, 1);

    for (auto n : a) cout << n;
    cout << '\n';

    int opercnt[4] = {1,2,3,4};
    int oper[10] = {0, };
    int tmp = 0;

    for (int i = 0; i < 4; i++) {
        fill(oper+tmp, oper+tmp+opercnt[i], i);
        tmp += opercnt[i];
    }

    for (int i = 0; i < 10; i++) cout << oper[i];
}