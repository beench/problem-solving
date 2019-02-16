#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int main() 
{
    int n;
    char option;
    string str;
    vector<string> msg;
    int l = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> option;
        if (option == 'i') {
            cin >> str;
            msg.insert(msg.begin()+l, str);
            l++;
        } 
        else if (option == 'l') {
            if (l > 0) {
                l--;
            }
        } 
        else if (option == 'r') {
            if (l < msg.size()) {
                l++;
            }
        } 
        else if (option == 'b') {
            if (l > 0) {
                msg.erase(msg.begin()+l-1);
                l--;
            }
        } 
        else if (option == 'd') {
            if (l < msg.size()) {
                msg.erase(msg.begin()+l);
            }
        }
    }

    for (vector<string>::iterator i = msg.begin(); i != msg.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}