#include <iostream>
using namespace std;

main()
{
    char inp[100];
    cin >> inp;
    for (int i = 0; inp[i] != '\0'; i++) {
        if (inp[i] >= 'a' && inp[i] <= 'z'){
            inp[i] = inp[i]-'a'+'A';
        }
    }
    for (int i = 0; inp[i] != '\0'; i++){
        cout << inp[i];
    }
    cout << endl;
}