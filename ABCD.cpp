#include <iostream>

using namespace std;

bool check_condition(int x)
{
    if (0 < x && x < 1000){
        return true;
    }
    else return false;
}

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (check_condition(a) && check_condition(b) && check_condition(c) && check_condition(d)){
        cout << a+b+c+d << endl;
    }
}