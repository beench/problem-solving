/*
TASK: fin59_2_good
*/

#include<iostream>
#include<cmath>

using namespace std;

int n, m;
float input[21][21];

float avg(int a, int b)
{
    float sum = 0, cnt = 0;;
    for (int i = 0; i < n; i++) {
        if (i != a) {
            // cout << "==" << abs(input[a][b] - input[i][b]) << endl;
            sum += abs(input[a][b] - input[i][b]);
            cnt++;
        }
    }
    for (int j = 0; j < m; j++) {
        if (j != b) {
            // cout << "==" << abs(input[a][b] - input[a][j]) << endl;
            sum += abs(input[a][b] - input[a][j]);
            cnt++;
        }
    }
    float x = sum/cnt;
    // cout << x << endl;
    return x;
}


main() 
{    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> input[i][j];
        }
    }
    float min = 1000001;
    int minvalue = 0;
    for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
            int ans = avg(i,j);
            if(ans < min) {
                min = ans;
                minvalue = input[i][j];
            }
         }
     }
    cout << minvalue << endl;
     
 }