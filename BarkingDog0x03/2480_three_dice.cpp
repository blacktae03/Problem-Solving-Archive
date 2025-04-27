#include <bits/stdc++.h>
using namespace std;

void swap(int & a, int & b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A, B, C, tmp, res = 0;

    cin >> A >> B >> C;

    if(A > C) swap(A, C);
    if(A > B) swap(A, B); // ABC를 a 배열에 저장한 후 sort(a, a+3) 하면 정렬
    if(B > C) swap(B, C);
    // max({A, B, C}) 하면 최댓값 저장 가능
    if(A == B && B == C) res = 10000 + B * 1000;
    else if(A == B || B == C) res = 1000 + B * 100;
    else if(!res) res = C * 100; 

    cout << res; 

    return 0;
        
}