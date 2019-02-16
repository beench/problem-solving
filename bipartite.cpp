#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_N 100010

int n, m;
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
int layer[MAX_N];

void init()
{
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        layer[i] = -1;
    }
}

bool isBipartite(int s) 
{
    layer[s] = 0;

    queue<int> q;
    q.push(s);

    while(!q.empty()) {
        int a = q.front();
        q.pop();
        visited[a] = true;
        // cout << u+1 << endl;
        for (int i = 0; i < deg[a]; i++) {
            int b = adj[a][i];
            if (layer[b] == -1) {
                layer[b] = 1 + layer[a];
                q.push(b);
            }
            else if (layer[b] == layer[a]) {
                return false;
            }
        }
    }
    return true;
}

main()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        read_input();
        init();
        bool bipartite = isBipartite(0);
        if (bipartite) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
        for(int i = 0; i < n; i++) {
            adj[i].clear();
        }
    }
}