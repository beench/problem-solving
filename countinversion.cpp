#include <iostream>

using namespace std;

int n;
int first = 0;
int last = n-1;
int A[100100];
int sortA[100100];
long long cntInv = 0;

int countInversionMerge(int first, int last)
{

}

int countInversion()
{
    int mid = last/2;
    int i = first;
    int j = mid+1;
    long long cnt_left = 0, cnt_right = 0, cnt_cross = 0;
    if ()
    cnt_left = countInversion(i, mid);
    cnt_right = countInversion(j, n);
    cnt_cross = countInversionMerge(first, last);
    return cnt_left + cnt_right + cnt_cross;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    countInversion()
}