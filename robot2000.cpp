#include <iostream>

using namespace std;

void get_direction(char inp, char &dir, string &out)
{
    if (inp == 'N') {
        if (dir == inp) out += "F";
        else if (dir == 'E') out += "RRRF";
        else if (dir == 'S') out += "RRF";
        else if (dir == 'W') out += "RF";
        dir = 'N';
    }
    else if (inp == 'E') {
        if (dir == inp) out += "F";
        else if (dir == 'S') out += "RRRF";
        else if (dir == 'W') out += "RRF";
        else if (dir == 'N') out += "RF";
        dir = 'E';
    }
    else if (inp == 'S') {
        if (dir == inp) out += "F";
        else if (dir == 'W') out += "RRRF";
        else if (dir == 'N') out += "RRF";
        else if (dir == 'E') out += "RF";
        dir = 'S';
    }
    else if (inp == 'W') {
        if (dir == inp) out += "F";
        else if (dir == 'N') out += "RRRF";
        else if (dir == 'E') out += "RRF";
        else if (dir == 'S') out += "RF";
        dir = 'W';
    }
    else if (inp == 'Z') {
        out += "Z";
        dir = 'N';
    }
}

int main ()
{
    string inp;
    cin >> inp;
    char direction = 'N';
    string out = "";
    for (int i = 0; i < inp.size(); i++){
        get_direction(inp[i], direction, out);
    }
    cout << out << endl;
}