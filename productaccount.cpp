#include <iostream>
#include <map>

using namespace std;

int main()
{
    int m, option, type, num;
    cin >> m;
    map<int,int> godung;
    for (int i = 0; i < m; i++) {
        cin >> option >> type;
        if (option == 1) {
            cin >> num;
            godung[type] += num;
        } else if (option == 2) {
            cout << godung[type] << endl;
        } else if (option == 3) {
            cin >> num;
            if (godung[type] - num < 0) {
                cout << godung[type] << endl;
                godung[type] = 0;
            } else {
                godung[type] -= num;
                cout << num << endl;
            }
        }
    }
}