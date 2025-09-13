#include <bits/stdc++.h>
using namespace std;

bool isCycle(int u,int p,vector<vector<int>> & graph,vector<int> & vist,vector<int> & visc,vector<int> & par)
{
    if(vist[u])return false;
    if(visc[u])return true;

    visc[u] = 1;

    for(int v : graph[u])
    {
        if(isCycle(v,u,graph,vist,visc,par))
        {
            par[u] = v;
            vist[u] = 1;

            return true;
        }
    }

    vist[u] = 1;

    return false;
}

void solve()
{
    int N,M;
    cin>>N>>M;

    vector<vector<int>> graph(N+1,vector<int>());
    for(int i=0;i<M;i++)
    {
        int u,v;
        cin>>u>>v;

        graph[u].push_back(v);
    }

    vector<int> par(N+1,-1);
    vector<int> vist(N+1,0);
    vector<int> visc(N+1,0);

    int node = 0;
    for(int i=1;i<=N;i++)
    {
        if(isCycle(i,-1,graph,vist,visc,par))
        {
            node = i;
            break;
        }
    }

    if(node == 0)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    for(int i=0;i<N;i++)
    {
        node = par[node];
    }
    
    int fir = node;
    node = par[node];
    vector<int> res = {fir};
    while(node != fir)
    {
        res.push_back(node);
        node = par[node];
    }

    cout << res.size()+1 << '\n';
    for(int v : res)
    {
        cout << v << ' ';
    }
    cout << fir << '\n';
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