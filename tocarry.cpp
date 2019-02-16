/*
TASK: uva10469_tocarry
*/

#include<iostream>
#include<stdio.h>

using namespace std;

main() 
{
    unsigned int a, b, ans;

    while(cin >> a >> b) {
        ans = 0;
        ans = a ^ b;
        cout << ans << endl;
    }
}