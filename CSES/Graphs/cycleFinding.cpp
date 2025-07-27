#include <bits/stdc++.h>
using namespace std;

#define int long long

int cyci = -1;
unordered_map<int,int> bellmanFord(int V, vector<vector<int>>& edges, int src)
{
    vector<int> ans(V+1,1e14);
    ans[src] = 0;
    unordered_map<int,int> ptrs;

    for(int i=0;i<V;i++)
    {
        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            if(ans[u] + wt < ans[v])
            {
                if(i >= V-1)cyci = u;
                ans[v] = ans[u] + wt;
                ptrs[v] = u;
            }
        }
    }
    
    return ptrs;
}

void solve()
{
    int N,M;
    cin>>N>>M;

    vector<vector<int>> edges(M);
        
    for(int i=0;i<M;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
    
        edges[i] = {u,v,c};
    }

    auto v = bellmanFord(N,edges,1);

    if(cyci!=-1)
    {
        cout << "YES\n";
        int a = cyci;
        for(int i=0;i<N;i++)a = v[a];

        vector<int> out;
        int b = a;
        do
        {
            out.push_back(b);
            b = v[b];
        } while (b!=a);

        for(auto it=out.rbegin();it!=out.rend();it++)
        {
            cout << *it << ' ';
        }
        cout << *out.rbegin();
    }
    else cout << "NO\n";
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