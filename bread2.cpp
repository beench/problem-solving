#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int N, Q, numHouse;
    cin >> N >> Q;
    int breadStore[N][3];


    for (int i = 0; i < N; i++) {
        cin >> breadStore[i][0] >> breadStore[i][1] >> breadStore[i][2];
    }

    int tmpPrice = 1000001, tmpStore;
    for (int i = 0; i < Q; i++) {
        cin >> numHouse;
        for (int j = 0; j < N; j++) {
            if (breadStore[j][0] - numHouse >= -5 && breadStore[j][0] - numHouse <= 5) {
                if (breadStore[j][2] > 0) {
                    if (breadStore[j][1] < tmpPrice) {
                        tmpPrice = breadStore[j][1];
                        tmpStore = j;
                    }
                }
            }
        }
        if (tmpPrice == 1000001) {
            printf ("0 \n");
        }
        else {
            breadStore[tmpStore][2]--;
            printf ("%d \n", tmpPrice);
            tmpPrice = 1000001;
        }
    }
}