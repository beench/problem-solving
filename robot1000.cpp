#include <iostream>

using namespace std;

void get_direction(char dir, int &x, int &y)
{
    if (dir == 'N') {
        y += 1;
    }
    else if (dir == 'S') {
        y -= 1;
    }
    else if (dir == 'E') {
        x += 1;
    }
    else if (dir == 'W') {
        x -= 1;
    }
    else if (dir == 'Z') {
        x = 0; 
        y = 0;
    }
}

int main ()
{
    string inp;
    cin >> inp;
    int x = 0, y = 0;
    for (int i = 0; i < inp.size(); i++){
        get_direction(inp[i], x, y);
    }
    cout << x << ' ' << y << endl;
}