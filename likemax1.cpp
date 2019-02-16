#include <iostream>
#include <map>
#include <stdio.h>

using namespace std;

int main() 
{
    int n, status, max = -1, ans;
    bool isFirst = true;
    scanf("%d", &n);
    map<int,int> likeStatus;
    for (int i = 0; i < n; i++) {
        scanf("%d", &status);
        likeStatus[status]++;
        if (isFirst) {
            ans = status;
            isFirst = false;
        }
        if (likeStatus[status] >= max) {
            max = likeStatus[status];
            ans = status;
        }
        printf("%d\n", ans);
    }
}