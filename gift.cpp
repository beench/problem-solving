#include <iostream>

using namespace std;

int compute(int x[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++){
        if (x[i] > 0) sum += x[i];
    }
    return sum;
}

main()
{
    int n;
    cin >> n;
    int gifts[n];
    for (int i = 0; i < n; i++){
        cin >> gifts[i];
    }
    cout << compute(gifts, n) << endl;
}