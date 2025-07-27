#include <bits/stdc++.h>
using namespace std;

#define int long long

void dfs(int node,int sum,vector<vector<pair<int,int>>> & adj,vector<int> &ans,multiset<pair<int,int>> &s,int* vis)
{
    for(auto &v : adj[node])
    {
        if(vis[v.first] == 0)
        {
            s.insert({v.second + sum,v.first});
        }
        ans[v.first] = min(v.second + sum,ans[v.first]);
    }
    
    vis[node] = 1;
    
    while(s.size() && vis[(*s.begin()).second]==1)
    {
        s.erase(s.begin());
    }
    
    if(s.size())
    {
        dfs((*s.begin()).second,(*s.begin()).first,adj,ans,s,vis);
    }
}

vector<int> dijkstra(int V, vector<vector<pair<int,int>>> & adj, int S)
{
    vector<int> ans(V+1,(int)1e15);
    
    multiset<pair<int,int>> s;
    
    int vis[V+1];
    for(int i=1;i<=V;i++)vis[i] = 0;

    ans[S] = 0;
    dfs(S,0,adj,ans,s,vis);
    
    return ans;
}

void solve()
{
    int N,M;
    cin>>N>>M;

    vector<vector<pair<int,int>>> graph(N+1);
    vector<pair<pair<int,int>,int>> edges;

    for(int i=0;i<M;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
    
        graph[u].push_back({v,c});
        edges.push_back({{u,v},c});
    }

    auto v1 = dijkstra(N,graph,1);

    vector<vector<pair<int,int>>> invgraph(N+1);

    for(int u=1;u<=N;u++)
    {
        for(auto [v,c] : graph[u])
        {
            invgraph[v].push_back({u,c});
        }
    }

    auto v2 = dijkstra(N,invgraph,N);

    int ans = 1e15;
    for(auto [p,c] : edges)
    {
        auto [u,v] = p;

        int d1 = v1[u];
        int d2 = v2[v];

        int d = d1 + d2 + c/2;
        ans = min(ans,d);
    }

    cout << ans << '\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/CP/input.txt", "r", stdin);
        freopen("/home/om/Acads/CP/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    solve();

    return 0;
}