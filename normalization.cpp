#include <iostream>

using namespace std;

int compute_gcd(int x, int y){
    int gcd = 1;
    for (int i = 1; i <= y; i++){
        if(x%i == 0 && y%i == 0){
            
            if (i>gcd)
                gcd = i;
        }
    }
    return gcd;
}

main()
{
    int a, b, gcd;
    cin >> a >> b;
    if(a < b){
        gcd = compute_gcd(a,b);
    }
    else{
        gcd = compute_gcd(b,a);
    }
    cout << a/gcd << "/" << b/gcd << endl;
}