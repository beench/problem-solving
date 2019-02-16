#include <iostream>
using namespace std;

main()
{
    char inp[1000];
    cin >> inp;
    int cnt = 0;
    for (int i = 0; inp[i] != '\0'; i++) {
        cnt++;
    }
    char out[1000];
    int n=0;
    for (int i = cnt-1; i >= 0; i--) {
        out[n++] = inp[i];
    }
    for (int i = 0; out[i] != '\0'; i++){
        cout << out[i];
    }
    cout << endl;
}