#include<iostream>
#include<cmath>

using namespace std;

int L, H, R;
int input[101][101];
int output[101][101];

int avgPoint(int i, int j)
{
    int sum = 0, cnt = 0,been = 1;

    for (int x = i-R; x <= i+R; x++) {
        // cout << " ====" << endl;
        for (int y = j-R; y <= j+R; y++) {
            if (abs(i-x) + abs(j-y) <= R) {
                // cout << "-----" << endl;
                if (x < 0 || x >= H || y < 0|| y >= L) {
                    continue;
                }
                sum += input[x][y];
                cnt++;
            }
        }
    }
    // for (int z = R; z > 0; z--) {
    //     if (i-z >= 0) {
    //         sum += input[i-z][j];
    //         cnt++;
    //         cout << "in5" << endl;
    //     }
    //     if (i+z < H) {
    //         sum += input[i+z][j];
    //         cnt++;
    //         cout << "in6" << endl;
    //     }
    // }
    // for (int z = R; z > 0; z--) {
    //     if (j-z >= 0) {
    //         sum += input[i][j-z];
    //         cnt++;
    //         cout << "in7" << endl;
    //     }
    //     if (j+z < L) {
    //         sum += input[i][j+z];
    //         cnt++;
    //         cout << "in8" << endl;
    //     }
    // }
    // sum += input[i][j];
    //cnt++;
    // cout << "====" << cnt << endl;
    output[i][j] = sum/cnt;
    // cout << output[i][j] << endl;
}

void newPic()
{
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < L; j++) {
            avgPoint(i, j);
        }
    }
}

main()
{
    cin >> L >> H >> R;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < L; j++) {
            cin >> input[i][j];
        }
    }
    newPic();
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < L; j++) {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }

}