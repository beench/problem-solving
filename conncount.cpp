#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 100010

int n, m, cnt = 0;
vector<int> adj[MAX_N];
int deg[MAX_N];

void read_input()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        deg[i] = 0;
    }
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        deg[a]++;
        //if undirected graph
        adj[b].push_back(a);
        deg[b]++;
    }
}

bool visited[MAX_N];

void init()
{
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
}

void dfs(int a) 
{
    visited[a] = true;
    // cout << (a+1) << endl;
    for (int i = 0; i < deg[a]; i++) {
        int v = adj[a][i];
        if(!visited[v]) {
            dfs(v);
        }
    }
}

void conncom()
{
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            cnt++;
            dfs(i);
        }
    }
}

main() 
{
    read_input();
    init();
    conncom();
    cout << cnt << endl;
}