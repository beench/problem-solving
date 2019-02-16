/*
TASK: uva100_3n+1
*/

#include<iostream>
#include<stdio.h>

using namespace std;

main()
{
    int a, b, x, y;
    while(!cin.eof()) {
        cin >> a >> b;
        if (a > b) {
            x = b; 
            y = a;
        } else {
            x = a; 
            y = b;
        }
        int max = 0;
        for(int n = x; n <= y; n++) {
            // cout << "===" << endl;
            int cnt = 1;
            int num = n;
            while (num != 1) {
                cnt++;
                if(num%2 == 0) {
                    num = num/2;
                }
                else if(num%2 != 0) {
                    num = (3*num)+1;
                }
            }
            if(num == 1) {
                if (cnt > max) {
                    max = cnt;
                }
                continue;
            }
        }
        cout << a << " " << b << " " << max << endl;
    }
}