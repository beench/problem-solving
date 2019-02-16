/*
TASK: searchsum1
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int nBook, k, tmp, money, sum, ans;
    vector<int> sumPrice;
    cin >> nBook >> k;

    for (int i = 0; i < nBook; i++) {
        cin >> tmp;
        sum += tmp;
        sumPrice.push_back(sum);
    }

    for (int i = 0; i < k; i++) {
        cin >> money;
        ans = upper_bound(sumPrice.begin(), sumPrice.end(), money) - sumPrice.begin();
        cout << ans << endl;
    }
}