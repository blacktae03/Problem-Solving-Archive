// 6월 15일은 게리맨더링을 포함한 여러 못푼 문제들 다시 풀고 16일부터 정렬 공부할 생각하기.

#include <bits/stdc++.h>
using namespace std;

int N;
int brd[22][22], num[22][22], sum[6], vis[22][22];
int ans = 99999999;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> brd[i][j];
        }
    }

    for (int d1 = 1; d1 <= N-1; d1++) {
        for (int d2 = 1; d1+d2 <= N-1; d2++) {
            for (int x = 1; x+d1+d2 <= N; x++) {
                for (int y = 1+d1; y+d2 <= N; y++) {

                    int nx = x, ny = y;
                    
                    for (int i = 0; i < d1; i++) {
                        num[nx][ny] = 5;
                        nx++;
                        ny--;
                    }

                    int leftendrow = nx, leftendcol = ny;
                    
                    for (int i = 0; i < d2; i++) {
                        num[nx][ny] = 5;
                        nx++;
                        ny++;
                    }

                    int endrow = nx, endcol = ny;

                    for (int i = 0; i < d1; i++) {
                        num[nx][ny] = 5;
                        nx--;
                        ny++;
                    }

                    int rightendrow = nx, rightendcol = ny;

                    for (int i = 0; i < d2; i++) {
                        num[nx][ny] = 5;
                        nx--;
                        ny--;
                    }

                    bool inborder = 0;

                    for (int i = 1; i <= N; i++) {
                        for (int j = 1; j <= N; j++) {
                            if (num[i][j] != 5) {
                                if (inborder) {sum[5] += brd[i][j]; num[i][j] = 5;}
                                else if (i < leftendrow && j <= y) {sum[1] += brd[i][j]; num[i][j] = 1;}
                                else if (i <= rightendrow && j > y) {sum[2] += brd[i][j]; num[i][j] = 2;}
                                else if (i >= x+d1 && j < endcol) {sum[3] += brd[i][j]; num[i][j] = 3;}
                                else if (i > x+d2 && j >= endcol) {sum[4] += brd[i][j]; num[i][j] = 4;}
                            }

                            else {
                                sum[5] += brd[i][j];
                                vis[i][j] = 1;

                                if (i > x && i < endrow) inborder = !inborder;
                            }

                            cout << num[i][j] << ' ';
                        }
                        fill(num[i], num[i]+22, 0);
                        cout << '\n';
                    }
                    cout << '\n';
                    // for (int i = 1; i <= N; i++) {
                    //     for (int j = 1; j <= N; j++) {
                    //         if (!vis[i][j]) {
                    //             cout << "d1 = " << d1 << ", d2 = " << d2 << ", x = " << x<< ", y = " << y << "*" << i << " " << j << "*\n";
                    //         }
                    //     }
                    //     fill(vis[i], vis[i]+22, 0);
                    // }

                    ans = min(*max_element(sum+1, sum+6) - *min_element(sum+1, sum+6), ans);
                    fill (sum, sum+6, 0);
                }
            }
        }
    }

    cout << ans;
}