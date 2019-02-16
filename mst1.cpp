#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define MAX_N 100010

int n, m;
int parent[MAX_N];
int deep[MAX_N];
vector<pair<int,pair<int, int> > > adj;

void read_input()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj.push_back(make_pair(w, make_pair(a,b)));
    }
}


void init()
{
    for (int i = 0; i < n+1; i++) {
        parent[i] = i;
        deep[i] = 1;
    }
}

int find(int x)
{
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void Union(int x, int y) 
{
    int x_parent = find(x);
    int y_parent = find(y);
    if (deep[x_parent] < deep[y_parent]) {
        parent[x_parent] = y_parent;
        deep[y_parent] += deep[x_parent];
    } else {
        parent[y_parent] = x_parent;
        deep[x_parent] += deep[y_parent];
    }
    // cout << "parent : " << parent[x_parent] << endl;
}

int MST()
{
    int cnt = 0;
    sort(adj.begin(), adj.end());
    for (int i = 0; i < m; i++) {
        int x = adj[i].second.first;
        int y = adj[i].second.second;
        int parent_x = find(x);
        int parent_y = find(y);
        if (parent_x != parent_y) {
            cnt += adj[i].first;
            Union(x,y);
        }
    }
    return cnt;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    read_input();
    init();
    cout << MST() << endl;
}