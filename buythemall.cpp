#include <iostream>

using namespace std;

main()
{
    int p1, p2, p3, first = 0, second = 0, third = 0;
    cin >> p1 >> p2 >> p3;
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++){
        cin >> x;
        if (x == 1) {
            first += p1;
        }
        else if (x == 2) {
            second += p2;
        }
        else if (x == 3) {
            third += p3;
        }
    }

    int minprice = 9999999;
    
    if (first < minprice && first != 0) 
        minprice = first;
    if (second < minprice && second != 0) 
        minprice = second;
    if (third < minprice && third != 0) 
        minprice = third;

    cout << minprice << endl;
}