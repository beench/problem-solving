#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vec;
typedef pair<int,int> pa;
typedef vector< pa > vecpa;

#define MAX_N 100010
#define INF 0x3f3f3f3f

int n, m;
vecpa adj[MAX_N];
vec dist(MAX_N, INF);

void read_input()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w; a--; b--;
        adj[a].push_back(make_pair(b,w));
        //if undirected graph
        adj[b].push_back(make_pair(a,w));
    }
}

void dijkstra(int s)
{
    priority_queue<pa, vector<pa>, greater<pa> > q;
    dist[s] = 0;
    q.push(make_pair(0, s));

    while(!q.empty()) {
        int u = q.top().second;
        q.pop();
        vector<pa>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); i++) {
            int v = (*i).first;
            int weight = (*i).second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                q.push(make_pair(dist[v], v));
            }
        }
    }
}

main() 
{
    read_input();
    dijkstra(0);
    cout << dist[n-1] << endl;
}