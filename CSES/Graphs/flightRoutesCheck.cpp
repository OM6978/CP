#include <bits/stdc++.h>
using namespace std;

void dfs1(int u,stack<int> & s,vector<vector<int>> & graph,vector<int> & vis)
{
    vis[u] = 1;

    for(int v : graph[u])
    {
        if(vis[v] == 0)
            dfs1(v,s,graph,vis);
    }

    s.push(u);
}

void dfs2(int u,vector<vector<int>> & graph,vector<int> & vis,vector<int> & comp)
{
    vis[u] = 1;
    comp.push_back(u);

    for(int v : graph[u])
    {
        if(vis[v] == 0)
        {
            dfs2(v,graph,vis,comp);
        }
    }
}

vector<vector<int>> kosaRaju(vector<vector<int>> & graph)
{
    int N = graph.size() - 1;
    
    vector<int> vis(N+1,0);
    stack<int> s;
    for(int i=1;i<=N;i++)
    {
        if(vis[i] == 0)
            dfs1(i,s,graph,vis);
    }

    vector<vector<int>> invGraph(N+1,vector<int>());
    for(int u=1;u<=N;u++)
    {
        for(int v : graph[u])
        {
            invGraph[v].push_back(u);
        }
    }

    vis.assign(N+1,0);
    vector<vector<int>> scc;

    while(s.size())
    {
        int u = s.top();
        s.pop();

        if(vis[u] == 0)
        {
            scc.push_back({});
            dfs2(u,invGraph,vis,scc.back());
        }
    }

    return scc;
}

bool searchNode(int u,int goal,vector<vector<int>> & graph,vector<int> & vis)
{
    if(u == goal)return true;
    vis[u] = 1;

    for(int v : graph[u])
    {
        if(vis[v] == 0)
        {
            if(searchNode(v,goal,graph,vis))
            {
                return true;
            }
        }
    }

    return false;
}

void solve()
{
    int N,M;
    cin>>N>>M;

    vector<vector<int>> graph(N+1);
    
    for(int i=0;i<M;i++)
    {
        int u,v;
        cin>>u>>v;
    
        graph[u].push_back(v);
    }

    auto scc = kosaRaju(graph);

    if(scc.size() > 1)
    {
        cout << "NO\n";

        int u = scc[0][0];
        int v = scc[1][0];

        vector<int> vis(N+1,0);
        if(searchNode(u,v,graph,vis))
        {
            cout << v << ' ' << u << '\n';
        }
        else
        {
            cout << u << ' ' << v << '\n';
        }
    }
    else
    {
        cout << "YES\n";
    }
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