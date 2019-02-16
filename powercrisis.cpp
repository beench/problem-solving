/*
TASK: uva151_powercrisis
*/

#include<iostream>

using namespace std;

main() 
{
    int n;
    cin >> n;
    bool turnoff[n+1];
    int region;
    for (int i = 0; i <= n; i++) {
        turnoff[i] = false;
    }
    int cntregion = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j < n+i; j++) {
            if (turnoff[j%n] == false) {
                cnt++;
                cout << "==" << j%n << endl;
                if (cnt == 5) {
                    cntregion++;
                    turnoff[j%n] = true;
                    region = j%n;
                    int cnt = 0;
                    // break;
                }
            }
        }
    }
    if (cntregion == 15) {
                cout << region << endl;
            }
}