#include <bits/stdc++.h>
using namespace std;

int N, M;
int F, T; // five, two
vector<int> FV, TV;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    M = min(M, N-M);
    
    int tF = 1, tT = 1;
    while(tF < INT_MAX / 5) {
        FV.push_back(tF*5);
    }
    while(tT < INT_MAX / 2) {
        TV.push_back(tT*2);
    }


    while(M) {
        int tN = N, tM = M;

        if (!(tN % 5)) {
            F++;
            tN /= 5;
        }
        while (!(tN % 2)) {
            T++;
            tN /= 2;
        }
        while (!(tM % 5)) {
            F--;
            tM /= 5;
        }
        while (!(tM % 2)) {
            T--;
            tM /= 2;
        }

        N--;
        M--;
    }

    cout << min(F, T);
}
// 시간초과 뜰 수 밖에 없음.. 2b C 1b (최대 연산 수) 하면 1b번 연산해야함. 10억