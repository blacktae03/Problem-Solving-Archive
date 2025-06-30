#include <bits/stdc++.h>
using namespace std;

int N, K;
int brd[14][14];
vector<int> V[14][14]; // 각 칸에 쌓인 순서 표현
vector<tuple<int, int, int>> piece; // 말의 정보 (행좌표, 열좌표, 방향)

void move(int & px, int & py, int dir) {
    if (dir == 1) py++;
    else if (dir == 2) py--;
    else if (dir == 3) px--;
    else if (dir == 4) px++;
}

void dirChange(int & dir) {
    if (dir == 1) dir = 2;
    else if (dir == 2) dir = 1;
    else if (dir == 3) dir = 4;
    else if (dir == 4) dir = 3;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 0; i <= N+1; i++) {
        for (int j = 0; j <= N+1; j++) {
            if (!i || i == N+1) brd[i][j] = 2;
            else if (!j || j == N+1) brd[i][j] = 2;
            else cin >> brd[i][j];
        }
    }

    // cout << '\n';

    // for (int i = 0; i <= N+1; i++) {
    //     for (int j = 0; j <= N+1; j++) {
    //         cout << brd[i][j] << ' ';
    //     }
    //     cout <<'\n';
    // } // brd 출력 테스트
    
    for (int i = 0; i < K; i++) {
        int px, py, dir;
        cin >> px >> py >> dir;
        
        piece.push_back({px, py, dir});
        V[px][py].push_back(i);
    }
    
    // for (auto t : piece) cout << get<0>(t) << ' ' << get<1>(t) << ' ' << get<2>(t) << " | ";
    // cout << '\n'; // piece 출력 테스트
    
    // for (int i = 0; i <= N+1; i++) {
    //     for (int j = 0; j <= N+1; j++) {
    //         if (V[i][j].empty()) cout << "x ";
    //         else {
    //             // cout << '|';
    //             for (auto num : V[i][j]) cout << num;
    //             cout << ' ';
    //             // cout << '|';
    //         }
    //     }
    //     cout <<'\n';
    // } // V 출력 테스트
    // cout << '\n';

    int turn = 0;

    while(true) {
        turn++;
        if (turn > 1000) break;
        int pidx = 0;

        for (auto & p : piece) {
            int px, py, dir;
            tie(px, py, dir) = p;
            vector<int> piled; // 움직이려는 말을 포함한 그 위에 쌓인 말의 번호 기록하기
            int found = -1;
            for (int f = 0; f < V[px][py].size(); f++) {
                if (V[px][py][f] == pidx) found = f;
                if (found >= 0) piled.push_back(V[px][py][f]);
            }
            V[px][py].erase(V[px][py].begin()+found, V[px][py].end());

            // for (auto num : piled) cout << num << ' ';
            // cout << '\n';
            // piled 출력 테스트

            int tpx = px, tpy = py; // 이동하려는 칸
            move(tpx, tpy, dir);
            
            if (brd[tpx][tpy] == 2) {
                dirChange(dir);
                int ttpx = px, ttpy = py;
                move(ttpx, ttpy, dir);
                if (brd[ttpx][ttpy] != 2) {
                    move(px, py, dir);
                    if (brd[ttpx][ttpy] == 1) {
                        for (int i = 0; i < piled.size()/2; i++) swap(piled[i], piled[piled.size()-i-1]);
                    }
                }
            }
            
            else if (brd[tpx][tpy] == 1) {
                move(px, py, dir);
                for (int i = 0; i < piled.size()/2; i++) swap(piled[i], piled[piled.size()-i-1]);
            }

            else {
                move(px, py, dir);
            }

            for (auto i : piled) { // 쌓은 거 해당하는 좌표 벡터에 옮기기
                V[px][py].push_back(i);
                // piece[i] = {px, py, dir};
                get<0>(piece[i]) = px;
                get<1>(piece[i]) = py;
            }
            get<2>(piece[pidx]) = dir; // 옮기는 것만 방향도 같이 변경
            
        //     cout << "------ turn " << turn << " ------- " << pidx << '\n';
        //     for (int i = 0; i <= N+1; i++) {
        //         for (int j = 0; j <= N+1; j++) {
        //             if (V[i][j].empty()) cout << "x ";
        //             else {
        //                 // cout << '|';
        //                 for (auto num : V[i][j]) cout << num;
        //                 cout << ' ';
        //                 // cout << '|';
        //             }
        //         }
        //         cout << '\n';
        //     } // V 출력 테스트
        // // }

            if (V[px][py].size() >= 4) {
                cout << turn;
                return 0;
            }

            pidx++;
        }
    }

    cout << -1;
}

// 4 4
// 0 0 1 0
// 0 0 0 0
// 0 0 0 0
// 0 0 0 0
// 1 1 1
// 1 4 2
// 1 2 1
// 1 3 1
// 하면
// x x x x x x
// x x |2 0 ||3 ||1 | x
// x x x x x x
// x x x x x x
// x x x x x x
// x x x x x x

// x x x x x x
// x x |2 0 ||3 1| x x
// x x x x x x
// x x x x x x
// x x x x x x
// x x x x x x

// x x x x x x
// x x |3 1 0 2 | x x
// x x x x x x
// x x x x x x
// x x x x x x
// x x x x x x
