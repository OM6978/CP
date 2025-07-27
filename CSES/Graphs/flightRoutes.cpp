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

vector<int> dijkstra(int V, vector<vector<pair<int,int>>> adj, int S)
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
    int N,M,K;
    cin>>N>>M>>K;

    vector<vector<pair<int,int>>> graph(N+1);
        
    for(int i=0;i<M;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
    
        graph[u].push_back({v,c});
        graph[v].push_back({u,c});
    }

    auto v = dijkstra(N,graph,1);

    
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