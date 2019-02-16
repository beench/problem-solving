#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int line = 1; line <= n; line++){
        for (int i = 1; i <= n-line; i++) {
            cout << " ";
        }
        for (int i = 1; i <= line; i++) {
            cout << "*" ;
        }
        cout << endl;
    }
}