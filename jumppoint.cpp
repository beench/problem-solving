#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_N 100010

int n, r;
vector<int> adj[MAX_N];
pair<int,int> point[MAX_N];
int deg[MAX_N];
bool visited[MAX_N];
int layer[MAX_N];

void init()
{
    for (int i = 0; i <= n+1; i++) {
        visited[i] = false;
        layer[i] = -1;
        deg[i] = 0;
    }
}

void makeGraph() 
{
    for (int i = 0; i <= n+1; i++) {
        for (int j = i+1; j <= n+1; j++) {
            int disx = point[i].first - point[j].first;
            int disy = point[i].second - point[j].second;
            int distance = (disx*disx) + (disy*disy);
            if (distance <= r*r) {
                adj[i].push_back(j);
                deg[i]++;
                adj[j].push_back(i);
                deg[j]++;
            }
        }
    }
}

void bfs(int s) 
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
        }
    }
}

int main()
{
    cin >> n >> r;
    int x, y;
    point[0] = make_pair(0,0);
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        point[i] = make_pair(x,y);
    }
    point[n+1] = make_pair(100,100);
    init();
    makeGraph();
    bfs(0);
    if (layer[n+1] != -1) {
        cout << layer[n+1] << endl;
    } else cout << -1 << endl;

}