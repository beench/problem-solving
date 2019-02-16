#include <iostream>
#include <stdio.h>

using namespace std;

bool allPass(bool pass[]) 
{
    for (int i = 0; i < 3; i++) {
        if (pass[i] == false) {
            return false;
        }
    }
    return true;
}

int main() 
{
    int level, round, a, b, c, currentLv = 1, cnt = 0, tmpA, tmpB, tmpC;
    cin >> level >> round;
    int A[level-1], B[level-1], C[level-1];
    bool pass[3] = {false, false, false};
    bool isFirst = true;

    for (int i = 0; i < level-1; i++) {
        scanf("%d", &A[i]);
        scanf("%d", &B[i]);
        scanf("%d", &C[i]);
    }

    for (int i = 0; i < round; i++) {
        scanf("%d", &a);
        scanf("%d", &b);
        scanf("%d", &c);
        for (int j = 0;j < level-1; j++) {
            if (isFirst) {
                cout << "in1" << endl;
                tmpA = a;
                tmpB = b;
                tmpC = c;
                isFirst = false;
            }
            if (a > A[i]) {
                cout << "222" << endl;
                pass[0] = true;
                if (a > tmpA) {
                    tmpA = a;
                }
            }
            if (b > B[i]) {
                cout << "333" << endl;
                pass[1] = true;
                if (b > tmpB) {
                    tmpB = b;
                }
            }
            if (c > C[i]) {
                cout << "444" << endl;
                pass[2] = true;
                if (c> tmpC) {
                    tmpC = c;
                }
            }
            // if (!allPass(pass)) {
            //     cout << "666" << endl;
            //     break;
            // }
            if (allPass(pass)) {
                cout << "555" << endl;
                currentLv++;
                pass[0] = false;
                pass[1] = false;
                pass[2] = false;
                break;
            }
        }
    }
    cout << currentLv << endl;

}