#include<iostream>

using namespace std;
// int factorial(int x) 
// {
//     if (x == 1 || x == 0) {
//         return 1
//     }
//     else {
//         return 
//     }
// }

main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int sum = 1;
        for (int j = x; j > 0; j--) {
            sum += j;
        }
        cout << sum << endl;
    }
}