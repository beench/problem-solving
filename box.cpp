#include <iostream>
#include <vector>

using namespace std;

int n, m;
char map[40][40];
bool visited[40][40];
bool pass = false;

void init()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = false;
        }
    }
}

bool canPass(int x, int y) 
{
    if(!pass) {
        if (x < n-1 || y < m-1 || y >= 0 || x >= 0) {
            if (!visited[x][y]) {
                if (map[x][y] == '.' && map[x+1][y] == '.' && map[x][y+1] == '.' && map[x+1][y+1] == '.') {
                    visited[x][y] = true;
                    if (x == n-2) {
                        pass = true;
                        return 0;
                    }
                    canPass(x, y-1);
                    canPass(x+1, y);
                    canPass(x, y+1);
                    canPass(x-1, y);
                }
                return 0;
            }
            return 0;
        }
        return 0;
    }
    return 1;
}

main()
{
    cin >> n >> m;
    string tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        for (int j = 0; j < m; j++) {
            map[i][j] = tmp[j];
        }
    }

    init();
    for (int i = 0; i < m; i++) {
        if(canPass(0,i)) {
            cout << "yes" << endl;
            return 0;
        }
    }   
    cout << "no" << endl; 
}