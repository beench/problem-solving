/*
TASK: uva146_idcodes
*/

#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

main() 
{
    char id[51];
    while(cin >> id) {
        if (id[0] == '#') {
            break;
        }
        int size = strlen(id);
        if (next_permutation(id, id+size)) {
            cout << id << endl;
        }
        else {
            cout << "No Successor" << endl;
        }
    }
}