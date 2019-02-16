/*
TASK: uva10921_telephone
*/

#include<iostream>

using namespace std;

main()
{
    char input[31];
    while(cin >> input) {
        for (int i = 0; input[i]; i++) {
            if (input[i] >= 'A' && input[i] <= 'C') {
                cout << 2;
            }
            else if (input[i] >= 'D' && input[i] <= 'F') {
                cout << 3;
            }
            else if (input[i] >= 'G' && input[i] <= 'I') {
                cout << 4;
            }
            else if (input[i] >= 'J' && input[i] <= 'L') {
                cout << 5;
            }
            else if (input[i] >= 'M' && input[i] <= 'O') {
                cout << 6;
            }
            else if (input[i] >= 'P' && input[i] <= 'S') {
                cout << 7;
            }
            else if (input[i] >= 'T' && input[i] <= 'V') {
                cout << 8;
            }
            else if (input[i] >= 'W'&& input[i] <= 'Z') {
                cout << 9;
            }
            else {
                cout << input[i];
            }
        }
        cout << endl;
    }
}