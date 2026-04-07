#include <bits/stdc++.h>
using namespace std;

int main() {
    int brd[3][3] =
    {
        {0,0,0},
        {0,1,1},
        {0,0,0}
    };
    int tmp[3][3] =
    {
        {0,0,1},
        {0,0,1},
        {0,0,0}
    };
    for (int i = 0; i<3;i++) {
        for(int j=0;j<3;j++) {
            brd[i][j] = brd[i][j] || tmp[i][j];
        }
    }
    for (int i = 0; i<3;i++) {
        for(int j=0;j<3;j++) {
            cout << brd[i][j] << ' ';
        }
        cout << '\n';
    }

    int a = 3, b = -1;
    int c = a - b;
    cout << c;
}
