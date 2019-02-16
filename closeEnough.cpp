#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

int compare(int x[], int n, int l){
    int close = 0;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if(abs(x[i]-x[j]) <= l){
                close += 1;
            }
        }
    }
    return close;
}

int main()
{
    int n, l;
    cin >> n >> l;
    int house[n];
    for (int i = 0; i < n; i++){
        cin >> house[i]; 
    }
    int close = compare(house, n, l);
    cout << close << endl;

}

