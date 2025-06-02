#include <bits/stdc++.h>
using namespace std;

int r, c, x, y, K, com;
int brd[21][21];
vector<int> rdice, cdice;
bool stop;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> x >> y >> K;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> brd[i][j];
        }
    }
    
    for (int i = 0; i < 4; i++) {
        rdice.push_back(0);
        cdice.push_back(0);
    }
    
    for (int i = 0; i < K; i++) {
        if (!stop) {
            if (!brd[x][y]) brd[x][y] = rdice[2];
            else { rdice[2] = brd[x][y]; cdice[2] = brd[x][y]; brd[x][y] = 0; }
        }
        
        cin >> com;
        
        switch(com) {
            case 1 :
                y++;
                if(x < 0 || x >= r || y < 0 || y >= c) {y--; stop = 1; break;}
                rotate(rdice.begin(), rdice.begin()+1, rdice.end());
                cdice[0] = rdice[0];
                cdice[2] = rdice[2];
                cout << cdice[0] << '\n';
                stop = 0;
                break;
                
            case 2 :
                y--;
                if(x < 0 || x >= r || y < 0 || y >= c) {y++; stop = 1; break;}
                rotate(rdice.begin(), rdice.end()-1, rdice.end());
                cdice[0] = rdice[0];
                cdice[2] = rdice[2];
                cout << cdice[0] << '\n';
                stop = 0;
                break;
                
            case 3 :
                x--;
                if(x < 0 || x >= r || y < 0 || y >= c) {x++; stop = 1; break;}
                rotate(cdice.begin(), cdice.end()-1, cdice.end());
                rdice[0] = cdice[0];
                rdice[2] = cdice[2];
                cout << cdice[0] << '\n';
                stop = 0;
                break;
                
            case 4 :
                x++;
                if(x < 0 || x >= r || y < 0 || y >= c) {x--; stop = 1; break;}
                rotate(cdice.begin(), cdice.begin()+1, cdice.end());
                rdice[0] = cdice[0];
                rdice[2] = cdice[2];
                cout << cdice[0] << '\n';
                stop = 0;
                break;
        }
    }
}