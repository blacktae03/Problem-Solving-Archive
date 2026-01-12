#include <bits/stdc++.h>
using namespace std;

int N, M;
int F, T; // five, two
vector<int> FV, TV;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    int dif = N-M;
    
    int tF = 1, tT = 1;
    while(tF < INT_MAX / 5) {
        FV.push_back(tF*5);
        tF *= 5;
    }
    while(tT < INT_MAX / 2) {
        TV.push_back(tT*2);
        tT *= 2;
    }

    for (int i = 0; i < FV.size(); i++) {
        if (N < FV[i]) break;
        F += N / FV[i];
    }
    for (int i = 0; i < TV.size(); i++) {
        if (N < TV[i]) break;
        T += N / TV[i];
    }
    for (int i = 0; i < FV.size(); i++) {
        if (M < FV[i]) break;
        F -= M / FV[i];
    }
    for (int i = 0; i < TV.size(); i++) {
        if (M < TV[i]) break;
        T -= M / TV[i];
    }
    for (int i = 0; i < FV.size(); i++) {
        if (dif < FV[i]) break;
        F -= dif / FV[i];
    }
    for (int i = 0; i < TV.size(); i++) {
        if (dif < TV[i]) break;
        T -= dif / TV[i];
    }

    cout << min(F, T);
}
// 시간초과 뜰 수 밖에 없음.. 2b C 1b (최대 연산 수) 하면 1b번 연산해야함. 10억