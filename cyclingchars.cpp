#include <iostream>
using namespace std;

main()
{
    char inp[100];
    char out[100];
    cin >> inp;
    for (int i = 0; inp[i] != '\0'; i++){
        if (inp[i] >= 'w') {
            int tmp = 3-('z'-inp[i]);
            inp[i] = 'a' + tmp;
        }
        else inp[i] = inp[i]+4;
    }
    for (int i = 0; inp[i] != '\0'; i++){
        cout << inp[i];
    }
    cout << endl;
}