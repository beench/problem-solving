#include <iostream>
#include <stdio.h>
using namespace std;

struct Store
{
    int numStore;
    int price;
    int numBread;
};

int main()
{
    int N, Q, numHouse;
    cin >> N >> Q;
    struct Store breadStore[N];


    for (int i = 0; i < N; i++) {
        cin >> breadStore[i].numStore >> breadStore[i].price >> breadStore[i].numBread;
    }

    int tmpPrice = 1000001, tmpStore;
    for (int i = 0; i < Q; i++) {
        cin >> numHouse;
        for (int j = 0; j < N; j++) {
            if (breadStore[j].numStore - numHouse >= -5 && breadStore[j].numStore - numHouse <= 5) {
                if (breadStore[j].numBread > 0) {
                    if (breadStore[j].price < tmpPrice) {
                        tmpPrice = breadStore[j].price;
                        tmpStore = j;
                    }
                }
            }
        }
        if (tmpPrice == 1000001) {
            printf ("0 \n");
        }
        else {
            breadStore[tmpStore].numBread--;
            printf ("%d \n", tmpPrice);
            tmpPrice = 1000001;
        }
    }
}