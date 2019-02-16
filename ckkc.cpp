#include <iostream>

using namespace std;

main() 
{
    int x, input, cnt = 0;
    cin >> x;
    while (true) {  
        cnt++;
        cin >> input;
        if (input == 0) {
            break;
        }  
    }
    if ((cnt+1)%2 == 0) {
        if (x%2 == 0) cout << "K" << endl;
        else cout << "C" << endl;
    }
    else {
        if (x%2 == 0) cout << "C" << endl;
        else cout << "K" << endl;
    }
}