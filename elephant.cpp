/*
TASK: elephant
*/

#include<iostream>

using namespace std;

main() 
{
    int n;
    cin >> n;
    int banana[n];
    int point[n];
    for (int i = 0; i < n; i++) {
        cin >> banana[i];
        point[i] = 0;
    }
    for (int i = 0; i <n; i++) {
        if (i == 0 || i == 1) {
            point[i] = 0;
        }
        else if (i == 2) {
            point[i] = banana[2];
        }
        else if (point[i-3] + banana[i] > point[i-1]) {
            point[i] = point[i-3] + banana[i];
        }
        else {
            point[i] = point[i-1];
        }
    }
    cout << point[n-1] << endl;
}