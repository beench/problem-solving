#include <iostream>
using namespace std;

string rev(string word)
{
    int cnt = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        cnt++;
    }
    string out = "";
    int n=0;
    for (int i = cnt-1; i >= 0; i--) {
        out+= word[i];
    }
    return out;
}

main()
{
    char inp[1000];
    cin >> inp;
    string tmp = "";
    string out = "";
    for (int i = 0; inp[i] != '\0'; i++) {
        if (inp[i] == '_') {
            out += rev(tmp);
            out += '_';
            tmp = "";
        }
        else tmp+=inp[i];
    }
    out+=rev(tmp);
    for (int i = 0; out[i] != '\0'; i++){
        cout << out[i];
    }
    cout << endl;
}