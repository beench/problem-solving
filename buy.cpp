#include <iostream>
#include <stdio.h>
#include <set>

using namespace std;

int main() 
{
    int n; 
    long long a, b, x;
    cin >> n >> a >> b;
    set<long long> price;
    for (int i = 0; i < n; i++) {
        cin >> x;
        price.insert(x);
        // if (i > 0) {
        //     if (price[i-1] > price[i]) {
        //         long long tmp = price[i-1];
        //         price[i-1] = price[i];
        //         price[i] = tmp;
        //     }
        // }
    }

    if (b < a) {
        int tmp = b;
        b = a;
        a = tmp;
    }


    bool isFirst = true;
    int cnt = 0;
    for (set<long long>::iterator i = price.begin(); i != price.end(); i++) {
        for (set<long long>::iterator j = i+1; j != price.end() ; j++) {
            if (*i + *j >= a && *i + *j <= b) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}