#include <iostream>

using namespace std;

int main()
{
    int N, M, k;
    char order;
    cin >> N >> M;
    char table[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> table[i][j];
        }
    }
    for (int i = 0; i < M; i++) {
        cin >> order >> k;
        if (order == 'L') {
            for (int i = 0; i < N; i++) {
                if (table[k-1][i] != 'x') {
                    break;
                }
                table[k-1][i] = '.';
            }
        }
        if (order == 'R') {
            for (int i = N-1; i >= 0; i--) {
                if (table[k-1][i] != 'x') {
                    break;
                }
                table[k-1][i] = '.';
            }
        }
        if (order == 'U') {
            for (int i = 0; i < N; i++) {
                if (table[i][k-1] != 'x') {
                    break;
                }
                table[i][k-1] = '.';
            }
        }
        if (order == 'D') {
            for (int i = N-1; i >= 0; i--) {
                if (table[i][k-1] != 'x') {
                    break;
                }
                table[i][k-1] = '.';
            }
        }
        if (order == 'A') {
            for (int i = 0; i < N; i++) {
                if (table[k-1][i] == '.') {
                    table[k-1][i] = 'x';
                }
            }
        }
        if (order == 'B') {
           for (int i = 0; i < N; i++) {
                if (table[i][k-1] == '.') {
                    table[i][k-1] = 'x';
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << table[i][j];
        }
        cout << endl;
    }

}