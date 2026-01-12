#include <bits/stdc++.h>
using namespace std;

char firstcube[6][3][3], cube[6][3][3]; // 0 : 위, 1 : 아래, 2 : 앞, 3 : 뒤, 4 : 왼쪽, 5 : 오른쪽
string color = "wyrogb"; // 위 아래 앞 뒤 왼쪽 오른쪽 면 색깔 순서
int N, cnt;
int com[1001];

void clockwise(int cubing) {
    int tmpplane[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tmpplane[i][j] = cube[com[cubing]][i][j]; // 0은 나중에 각 면으로 고치기
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cube[com[cubing]][i][j] = tmpplane[2-j][i]; // 0은 나중에 각 면으로 고치기
        }
    }
}

void solve(int cubing, char way) {
    if (way == '+') clockwise(cubing);
    else {
        clockwise(cubing);
        clockwise(cubing);
        clockwise(cubing);
    } // 돌리는 면 회전시켜주기.

    string tmp = {"123456789123"};
    int order[4] = {0, };

    switch(com[cubing]) { // 기록하는 switch 문
        case 0: // 2, 5, 3, 4 순서로 기록 후 돌린 후 다시 기록.
            order[0] = 2, order[1] = 4, order[2] = 3, order[3] = 5;
            
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                    tmp[i*3+j] = cube[order[i]][0][2-j];
                }
            } // 12개 칸에 다 쭈루루룩 기록함.

            break;

        case 1: // 2, 5, 3, 4 순서로 기록 후 돌린 후 다시 기록.
            order[0] = 2, order[1] = 5, order[2] = 3, order[3] = 4;
            
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                    tmp[i*3+j] = cube[order[i]][2][j];
                }
            } // 12개 칸에 다 쭈루루룩 기록함.

            break;

        case 2: // 0, 5, 1, 4 순서로 기록 후 돌린 후 다시 기록.
            order[0] = 0, order[1] = 5, order[2] = 1, order[3] = 4;
            
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                    if (order[i] == 0) tmp[i*3+j] = cube[order[i]][2][j];
                    else if (order[i] == 1) tmp[i*3+j] = cube[order[i]][0][2-j];
                    else if (order[i] == 5) tmp[i*3+j] = cube[order[i]][j][0];
                    else if (order[i] == 4) tmp[i*3+j] = cube[order[i]][2-j][2];
                }
            } // 12개 칸에 다 쭈루루룩 기록함.

            break;

        case 3: // 0, 5, 1, 4 순서로 기록 후 돌린 후 다시 기록.
            order[0] = 0, order[1] = 4, order[2] = 1, order[3] = 5;
            
            for (int i = 0; i < 4; i++) { // 여기부터하기
                for (int j = 0; j < 3; j++) {
                    if (order[i] == 0) tmp[i*3+j] = cube[order[i]][0][2-j];
                    else if (order[i] == 1) tmp[i*3+j] = cube[order[i]][2][j];
                    else if (order[i] == 5) tmp[i*3+j] = cube[order[i]][2-j][2];
                    else if (order[i] == 4) tmp[i*3+j] = cube[order[i]][j][0];
                }
            } // 12개 칸에 다 쭈루루룩 기록함.

            break;
        
        case 4: // 0, 5, 1, 4 순서로 기록 후 돌린 후 다시 기록.
            order[0] = 0, order[1] = 2, order[2] = 1, order[3] = 3;
            
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                    if (order[i] == 0) tmp[i*3+j] = cube[order[i]][j][0];
                    else if (order[i] == 2) tmp[i*3+j] = cube[order[i]][j][0];
                    else if (order[i] == 1) tmp[i*3+j] = cube[order[i]][j][0];
                    else if (order[i] == 3) tmp[i*3+j] = cube[order[i]][2-j][2];
                }
            } // 12개 칸에 다 쭈루루룩 기록함.

            break;

        case 5: // 0, 5, 1, 4 순서로 기록 후 돌린 후 다시 기록.
            order[0] = 0, order[1] = 3, order[2] = 1, order[3] = 2;
            
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                    if (order[i] == 0) tmp[i*3+j] = cube[order[i]][2-j][2];
                    else if (order[i] == 3) tmp[i*3+j] = cube[order[i]][j][0];
                    else if (order[i] == 1) tmp[i*3+j] = cube[order[i]][2-j][2];
                    else if (order[i] == 2) tmp[i*3+j] = cube[order[i]][2-j][2];
                }
            } // 12개 칸에 다 쭈루루룩 기록함.

            break;
    }
    
    if (way == '+') {
        rotate(tmp.begin(), tmp.end()-3, tmp.end());
    }
    else {
        rotate(tmp.begin(), tmp.begin()+3, tmp.end());
    }

    switch(com[cubing]) { // 다시 큐브에 기록하는 switch 문
        case 0: // 2, 5, 3, 4 순서로 다시 기록.
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                    cube[order[i]][0][2-j] = tmp[i*3+j];
                }
            }
    
            break;
    
        case 1: // 2, 5, 3, 4 순서로 기록 후 돌린 후 다시 기록.            
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                    cube[order[i]][2][j] = tmp[i*3+j];
                }
            } // 12개 칸에 다 쭈루루룩 기록함.
    
            break;
    
        case 2: // 0, 5, 1, 4 순서로 기록 후 돌린 후 다시 기록.
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                    if (order[i] == 0) cube[order[i]][2][j] = tmp[i*3+j];
                    else if (order[i] == 1) cube[order[i]][0][2-j] = tmp[i*3+j];
                    else if (order[i] == 5) cube[order[i]][j][0] = tmp[i*3+j];
                    else if (order[i] == 4) cube[order[i]][2-j][2] = tmp[i*3+j];
                }
            } // 12개 칸에 다 쭈루루룩 기록함.
    
            break;
    
        case 3: // 0, 5, 1, 4 순서로 기록 후 돌린 후 다시 기록.
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                    if (order[i] == 0) cube[order[i]][0][2-j] = tmp[i*3+j];
                    else if (order[i] == 1) cube[order[i]][2][j] = tmp[i*3+j];
                    else if (order[i] == 5) cube[order[i]][2-j][2] = tmp[i*3+j];
                    else if (order[i] == 4) cube[order[i]][j][0] = tmp[i*3+j];
                }
            } // 12개 칸에 다 쭈루루룩 기록함.
    
            break;
        
        case 4: // 0, 5, 1, 4 순서로 기록 후 돌린 후 다시 기록.
            
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                    if (order[i] == 0) cube[order[i]][j][0] = tmp[i*3+j];
                    else if (order[i] == 2) cube[order[i]][j][0] = tmp[i*3+j];
                    else if (order[i] == 1) cube[order[i]][j][0] = tmp[i*3+j];
                    else if (order[i] == 3) cube[order[i]][2-j][2] = tmp[i*3+j];
                }
            } // 12개 칸에 다 쭈루루룩 기록함.
    
            break;
    
        case 5: // 0, 5, 1, 4 순서로 기록 후 돌린 후 다시 기록.
            
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                    if (order[i] == 0) cube[order[i]][2-j][2] = tmp[i*3+j];
                    else if (order[i] == 3) cube[order[i]][j][0] = tmp[i*3+j];
                    else if (order[i] == 1) cube[order[i]][2-j][2] = tmp[i*3+j];
                    else if (order[i] == 2) cube[order[i]][2-j][2] = tmp[i*3+j];
                }
            } // 12개 칸에 다 쭈루루룩 기록함.
    
            break;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int plane = 0; plane < 6; plane++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                firstcube[plane][i][j] = color[plane];
            }
        }
    }
    
    cin >> N;
    
    for (int test = 0; test < N; test++) {
        cin >> cnt;
        
        for (int plane = 0; plane < 6; plane++) { // 큐브 초기설정
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cube[plane][i][j] = firstcube[plane][i][j];
                }
            }
        }

        for (int cubing = 0; cubing < cnt; cubing++) {
            string tmp;
            cin >> tmp;

            switch(tmp[0]) {
                case 'U' :
                    com[cubing] = 0;
                    break;

                case 'D' :
                    com[cubing] = 1;
                    break;
                    
                case 'F' :
                    com[cubing] = 2;
                    break;

                case 'B' :
                    com[cubing] = 3;
                    break;

                case 'L' :
                    com[cubing] = 4;
                    break;

                case 'R' :
                    com[cubing] = 5;
                    break;
            }

            solve(cubing, tmp[1]);
        }


        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << cube[0][i][j];
            }
            cout << '\n';
        }
        // cout << '\n';
    }
}

// 0 : 위, 1 : 아래, 2 : 앞, 3 : 뒤, 4 : 왼쪽, 5 : 오른쪽 면이고
// 0 : 위, 1 : 아래, 2 : 앞, 3 : 뒤, 4 : 왼쪽, 5 : 오른쪽 면을 움직이는 명령이라고 했을 때,
// 명령이 0이면 0은 시계방향으로 돌린다. 앞, 왼쪽, 뒤, 오른쪽을 하나의 배열로 붙인 다음에 돌리는 함수 쓸까? 그리고 다시 붙여넣기?? 괜찮은데?
// 12
// 1
// U+
// 1
// U-
// 1
// D+
// 1
// D-
// 1
// F+
// 1
// F-
// 1
// B+
// 1
// B-
// 1
// L+
// 1
// L-
// 1
// R+
// 1
// R-