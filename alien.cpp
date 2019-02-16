/*
TASK: mid58_alien
*/

#include<iostream>

using namespace std;

main()
{
    int n, a, b, R, x, y, cnt = 0;
    cin >> n >> a >> b >> R;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        if (((a-x)*(a-x)) + ((b-y)*(b-y)) <= R*R) {
            cnt++;
        }
    }
    cout << cnt << endl;
}