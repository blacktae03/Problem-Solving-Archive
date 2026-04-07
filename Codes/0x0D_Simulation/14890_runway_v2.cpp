#include <bits/stdc++.h>
using namespace std;
#define VALUE v[v.size()-1].first
#define LENGTH v[v.size()-1].second


int N, L;
int brd[2][101][101];
int con[101];
int dx[2] = {1,-1};
vector<pair<int, int>> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L;

    int ans = 2*N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> brd[0][i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            brd[1][i][j] = brd[0][N-1-j][i]; // 회전한 것.
        }
    }

    for (int rc = 0; rc < 2; rc++) {
        for (int i = 0; i < N; i++) {
            v.clear();
    
            for (int j = 0; j < N; j++) {
                if (v.empty() || VALUE != brd[rc][i][j]) v.push_back({brd[rc][i][j], 1});
                else LENGTH++;
            } // 높이가 같은 연속된 길 한묶음으로 묶기
            
            bool esc = 0;
    
            for (int j = 0; j < v.size(); j++) {
                for (int dir = 0; dir < 2; dir++) { // 오른쪽 왼쪽 보기
                    int nx = j + dx[dir];
    
                    if (nx < 0 || nx >= v.size()) continue;
    
                    int ab = v[nx].first - v[j].first; 
    
                    if (abs(ab) > 1) { ans--; esc = 1; } // 0
                    else if (ab == 1) con[j]++;
                    
                    if (esc) break;
                }
                if (esc) break;
                if (con[j] && v[j].second < con[j] * L) { ans--; break; }
            }

            fill(con, con+101, 0);
        }
    }

    cout << ans;
}

// 일정한 높이가 유지되는 길을 한 묶음으로 봤을 때
// 0. 전 길의 높이보다 차이가 2이상 나면 그냥 탈락.
// 1. 올라가는 경사로만 필요한 경우 : 오른쪽 길이 나보다 1칸 높을 때 -> L칸 이상 필요
// 2. 내려가는 경사로만 필요한 경우 : 왼쪽 길이 나보다 1칸 높을 때 -> L칸 이상 필요
// 3. 양쪽에 둘 다 필요한 경우 : 왼쪽 길이 나보다 1칸 높고, 오른쪽 길이 나보다 1칸 높을 때 -> 2L칸 이상 필요
// 4. 필요없는 경우 : 왼쪽 길이 나보다 낮고, 오른쪽 길도 나보다 낮을 때 -> 0칸 필요
// 오른쪽 길이 나보다 높으면 case++
// 왼쪽 길이 나보다 높으면 case++
// case * L 보다 길의 길이가 작으면 탈락.
// 2*N만큼 반복