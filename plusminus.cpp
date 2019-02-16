#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int num;
    char sym;
    int sum;
    cin >> sum;
    for (int i = 0; i < n-1; i++) {
        cin >> sym >> num;
        if (sym == '+') {
            sum += num;
        }
        else if (sym == '-') {
            sum -= num;
        }
    }
    cout << sum << endl;
}