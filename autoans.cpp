/*
TASK: uva11547_automatic
*/

#include<iostream>
#include<cmath>

using namespace std;

main()
{
    int n;
    cin >> n;
    int x, ans;
    for (int i = 0; i < n; i++) {
        cin >> x;
        ans = ((((x*567)/9) + 7492 ) * 235 / 47 )- 498;
        if (ans < 0) {
            ans *= -1;
        }
        cout << ans/10%10 << endl;
    }
}