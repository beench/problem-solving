#include <iostream>
using namespace std;

bool checkparen(char* inp) 
{
    int firsth = 0, firstt = 0, sech = 0, sect = 0, thirdh = 0, thirdt = 0;
    for (int i = 0; inp[i] != '\0'; i++){
        if (inp[i] == '(') {
            firsth += 1;
            if (inp[i+1] == '}' || inp[i+1] == ']') return false;
        }
        else if (inp[i] == '{') {
            sech += 1;
            if (inp[i+1] == ')' || inp[i+1] == ']') return false;
        }
        else if (inp[i] == '[') {
            thirdh += 1;
            if (inp[i+1] == '}' || inp[i+1] == ')') return false;
        }
        else if (inp[i] == ')') {
            firstt += 1;
        }
        else if (inp[i] == '}') {
            sect += 1;
        }
        else if (inp[i] == ']') {
            thirdt += 1;
        }
        if (firstt > firsth || sect > sech || thirdt > thirdh) return false;
    }
    if (firsth - firstt == 0 && sech - sect == 0 && thirdh - thirdt == 0){
        return true;
    }
    else return false;
}

main()
{
    int t;
    cin >> t;
    bool check[t];
    for (int i = 0; i < t; i++){
        char inp[100];
        cin >> inp;
        check[i] = checkparen(inp);
    }
    for (int i = 0; i < t; i++){
        if (check[i] == true) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}