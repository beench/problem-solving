/*
LANG: C++
TASK: mid59_jumpgame
*/
#include <cstdio>
using namespace std;

int k;
int finish;
int **table;
bool **canJumpTable;
bool **path;

bool canJump(int row, int col, int prev) {
    //printf("Now: %d %d\n", row, col);
    bool result = false;
    if (!path[row][col] || table[row][col] > prev + k) {
        return false;
    }
    /* Finish point */
    if (row == finish && col == finish) {
        return true;        
    }

    path[row][col] = false;
    if (canJumpTable[row + 1][col] == true) {
        result = canJump(row + 1, col, table[row][col]);
    }
    if (!result && canJumpTable[row][col + 1] == true) {
        result = canJump(row, col + 1, table[row][col]);
    }
    if (!result && canJumpTable[row - 1][col] == true) {
        result = canJump(row - 1, col, table[row][col]);
    }
    if (!result && canJumpTable[row][col - 1] == true) {
        result = canJump(row, col - 1, table[row][col]);
    }
   
    path[row][col] = true;
    canJumpTable[row][col] = false;
    return result;
}

int main() {
    int n;
    scanf("%d %d", &n, &k);
    table = new int*[n + 2];
    canJumpTable = new bool*[n + 2];
    path = new bool*[n + 2];
    /* Set border */
    canJumpTable[0] = new bool[n + 2];
    canJumpTable[n + 1] = new bool[n + 2];
    path[0] = new bool[n + 2];
    path[n + 1] = new bool[n + 2];
    table[0] = new int[n + 2];
    table[n + 1] = new int[n + 2];
    for (int i = 0 ; i < n + 2; i++) {
        canJumpTable[0][i] = false;
        canJumpTable[n + 1][i] = false;
        path[0][i] = false;
        path[n + 1][i] = false;
        table[0][i] = 1000000;
        table[n + 1][i] = 1000000;
    }
    for (int i = 1; i < n + 1; i++) {
        canJumpTable[i] = new bool[n + 2];
        canJumpTable[i][0] =  false;
        path[i] = new bool[n + 2];
        path[i][0] =  false;
        table[i] = new int[n + 2];
        table[i][0] = 1000000;
        for (int j = 1; j < n + 1; j++) {
            int input;
            scanf("%d", &input);
            table[i][j] = input;
            canJumpTable[i][j] = true;
            path[i][j] = true;
        }
        canJumpTable[i][n + 1] = false;
        path[i][n + 1] = false;
        table[i][n+1] = 1000000;
    }

    finish = n;
    bool result = canJump(1, 1, 1000000);
    if (result) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}