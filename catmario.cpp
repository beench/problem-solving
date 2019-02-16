#include <iostream>

using namespace std;

int main()
{
    int N, M, num, time;
    cin >> N >> M;
    int game[M];
    for (int i = 0; i < N; i++) {
        game[i] = 501;
    }
    for (int i = 0; i < M; i++) {
        cin >> num >> time;
        if (time < game[num-1]) {
            game[num-1] = time;        
        }
    }
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += game[i];
    }
    cout << sum << endl;
    for (int i = 0; i < N; i++) {
        cout << i+1 << " " << game[i] << endl;
    }
}