#include <iostream>

using namespace std;

int countTrucks(int x[], int n){
    int trucks = 1;
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += x[i];
        if(sum > 1000){
            trucks += 1;
            sum = x[i];
        }
    }
    return trucks;
}

main(){
    int n;
    cin >> n;
    int packages[n];
    for (int i = 0; i < n; i++){
        cin >> packages[i];
    }
    int trucks = countTrucks(packages, n);
    cout << trucks << endl;

}