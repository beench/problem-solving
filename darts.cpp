/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <math.h>

using namespace std;

int check_score(int x, int y)
{
    float position = sqrt((x*x)+(y*y));
    int score;
    if (0 <= position && position <= 2)
        score = 5;
    else if (2 < position && position <= 4)
        score = 4;
    else if (4 < position && position <= 6)
        score = 3;
    else if (6 < position && position <= 8)
        score = 2;
    else if (8 < position && position <= 10)
        score = 1;
    else score = 0;
    return score;
}


int main()
{
    int n;
    int x, y;
    int sumscore = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        sumscore += check_score(x, y);
    }
    cout << sumscore << endl;
    
}



