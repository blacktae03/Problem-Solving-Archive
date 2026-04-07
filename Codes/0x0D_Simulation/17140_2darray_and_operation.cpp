#include <bits/stdc++.h>
using namespace std;
#define NUM first
#define CNT second

int r, c, k, rlen = 3, clen = 3, ans;
int brd[101][101];
map<int, int> M;
vector<pair<int, int>> V;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> r >> c >> k;
    
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> brd[i][j];
        }
    }
    
    while(ans < 101) {
        if (brd[r][c] == k) break;

        if (rlen >= clen) {
            int rmax = 0;

            for (int i = 1; i <= rlen; i++) {
                for (int j = 1; j <= clen; j++) {
                    if (!brd[i][j]) continue;
                    if (M.find(brd[i][j]) == M.end()) M.insert({brd[i][j], 1}); // 없으면
                    else M[brd[i][j]]++;
                }
                
                vector<pair<int, int>> V(M.begin(), M.end());
                sort(V.begin(), V.end(), [](pair<int, int> a, pair<int, int> b) {
                    if (a.second == b.second) return a.first < b.first;
                    else return a.second < b.second;
                }); // [] 사용하는 짧은 함수를 뭐라고 하는지, 무슨 뜻인지 다시 공부할 필요가 있음. 람다 함수

                int idx = 0;
                fill(brd[i], brd[i]+101, 0);
                for (auto n : V) {
                    brd[i][++idx] = n.NUM;
                    if (idx == 100) break;
                    brd[i][++idx] = n.CNT;
                    if (idx == 100) break;
                }
                
                rmax = max(rmax, idx);
                M.clear();
            }

            clen = rmax;
        }

        else {
            int cmax = 0;

            for (int i = 1; i <= clen; i++) {
                for (int j = 1; j <= rlen; j++) {
                    if (!brd[j][i]) continue;
                    if (M.find(brd[j][i]) == M.end()) M.insert({brd[j][i], 1}); // 없으면
                    else M[brd[j][i]]++;
                }
                
                vector<pair<int, int>> V(M.begin(), M.end());
                sort(V.begin(), V.end(), [](pair<int, int> a, pair<int, int> b) {
                    if (a.second == b.second) return a.first < b.first;
                    else return a.second < b.second;
                }); // [] 사용하는 짧은 함수를 뭐라고 하는지, 무슨 뜻인지 다시 공부할 필요가 있음. 람다 함수

                int idx = 0;

                for (int tmp = 0; tmp < 101; tmp++) brd[tmp][i] = 0;

                for (auto n : V) {
                    brd[++idx][i] = n.NUM;
                    if (idx == 100) break; 
                    brd[++idx][i] = n.CNT;
                    if (idx == 100) break;
                }

                cmax = max(cmax, idx);
                M.clear();
            }

            rlen = cmax;
        }

        ans++;

        // for (int i = 1; i <= 10; i++) {
        //     for (int j = 1; j <= 10; j++) {
        //         cout << brd[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';

    }

    if (ans == 101) cout << -1;
    else cout << ans;

}