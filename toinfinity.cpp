#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int N, x, y, r;
    bool isPass = true;
    cin >> N;
    int ans[N];
    for (int i = 0; i < N; i++) {
        cin >> x >> y >> r;
        if (y < 0) {
            ans[i] = y + r;
            if (ans[i] >= 0) {
                cout << -1 << endl;
                isPass = false;
                break;
            }
        }
        else if (y > 0) {
            ans[i] = y - r;
            if (ans[i] <= 0) {
                cout << -1 << endl;
                isPass = false;
                break;
            }
        }
        else {
            cout << -1 << endl;
            isPass = false;
            break;
        }
    }
    if (isPass) {
        int min = 9999999;
        for (int i = 0; i < N; i++) {
            ans[i] = abs(ans[i]);
            if(ans[i] < min) min = ans[i];
        }
        cout << min << endl;
    }
}