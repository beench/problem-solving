#include <iostream>

using namespace std;

int main() 
{
    int N, M, dice, player = 0;
    cin >> N >> M;
    int table[N+1];
    for (int i = 1; i <= N; i++) {
        cin >> table[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> dice;
        player += dice;
        if (player > N) player = N;
        player += table[player];
        if (player > N) player = N;
        else if (player < 1) player = 0;
    }
    cout << player << endl;
}