/*
TASK: mid592_water
*/

#include<iostream>

using namespace std;

main()
{
    int n, sum = 0;
    cin >> n;
    int water[n];
    for (int i = 0; i < n; i++) {
        cin >> water[i];
    }
    for (int i = 0; i < n-1; i++){
        if ((water[i] - water[i+1]) > 10) {
            // cout << "===" << i << endl;
            int x = (water[i]-water[i+1]) * 10;
            if (x > 700) {
                sum += 700;
            }
            else {
                sum += x;
            }
        }
    }
    cout << sum << endl;
}