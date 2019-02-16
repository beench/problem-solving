#include <iostream>
#include <stdio.h>
#include <set>

using namespace std;

int main() 
{
    int n; 
    long long a, b;
    cin >> n >> a >> b;
    long long price[n];
    for (int i = 0; i < n; i++) {
        cin >> price[i];
        if (i > 0) {
            if (price[i-1] > price[i]) {
                long long tmp = price[i-1];
                price[i-1] = price[i];
                price[i] = tmp;
            }
        }
    }

    if (b < a) {
        int tmp = b;
        b = a;
        a = tmp;
    }

    bool isFirst = true;
    int cnt = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (price[i] + price[j] >= a && price[i] + price[j] <= b) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}


int a[n];

int p = lower_bound(a, a+n, key)-a;


for(int i=0)
    p1 = lower_bound(a.begub+i, a+n, x-a[i])-a;
    p2 = 

    10
    60
    60
    60