#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n, m, bac, A, B;
    cin >> n >> m;
    int bacteria[n-1];
    for (int i = 0; i < n-1; i++) {
        cin >> bac;
        bacteria[i] = bac;
    }

    for (int i = 0; i < m; i++) {
        cin >> A >> B;
        if (bacteria[A-2] == B) {
            cout << B << endl;
        }
        else if (bacteria[B-2] == A) {
            cout << A << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
}