#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_N 100

int n, m, cnt = 0, excellent = 0, medium = 0;
string map[40];
vector<pair<int,int> > adj[MAX_N][MAX_N];
int deg[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
bool forest = false, mineral = false;

void init()
{
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            visited[i][j] = false;
            deg[i][j] = 0;
        }
    }
}

void makeGraph() 
{
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(map[i][j] != '#'){
                if(i+1 < n) { 
                    adj[i][j].push_back(make_pair(i+1,j));
                    deg[i][j]++;
                }
                if(i-1 >= 0) {
                    adj[i][j].push_back(make_pair(i-1,j));
                    deg[i][j]++;
                }
                if(j-1 >= 0) {
                    adj[i][j].push_back(make_pair(i,j-1));
                    deg[i][j]++;
                }
                if(j+1 < m) {
                    adj[i][j].push_back(make_pair(i,j+1));
                    deg[i][j]++;
                }
            }
        }
    }
}

void dfs(int a, int b) 
{
    visited[a][b] = true;
    // cout << (a+1) << endl;
    if(map[a][b] == '*') { 
        forest = true; // graph has forest(s)
    }
    if(map[a][b] == '$') {
        mineral = true; // graph has mineral(s)
    }
    if(map[a][b] != '#') {
        cnt++; // count ground(s) in the graph
    }
    for(int i = 0; i < deg[a][b]; i++) {
        // cout << "++++++++" << endl;
        pair<int,int> v = adj[a][b][i];
        if(!visited[v.first][v.second]) {
            // cout << "========" << endl;
            dfs(v.first,v.second);
        }
    }
}

main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> map[i];
    }
    init();
    makeGraph();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!visited[i][j]) {
                dfs(i,j); // one graph can be either excellent or medium quality
            }
            if(forest && mineral) {
                excellent += cnt;
                // cout << "in good" << endl;
            }
            else if(forest || mineral) {
                medium += cnt;
                // cout << "in med" << endl;
            }
            cnt = 0;
            forest = false;
            mineral = false;
        }
    }
    cout << excellent << " " << medium << endl;
 }

