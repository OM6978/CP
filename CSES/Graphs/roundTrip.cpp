#include <bits/stdc++.h>
using namespace std;

int isCycle(int a,int bef,vector<vector<int>> & graph,vector<int> & par)
{
    for(int b : graph[a])
    {
        if(b==bef)continue;

        if(par[b]!=-1)
        {
            par[b] = a;
            return a;
        }
        
        par[b] = a;
        int cycle = isCycle(b,a,graph,par);
        if(cycle)return cycle;
    }
    return 0;
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
        graph[v].push_back(u);
    }

    vector<int> par(N+1,-1);
    for(int i=1;i<=N;i++)
    {
        if(par[i]!=-1)continue;

        par[i] = 0;
        int cycle = isCycle(i,0,graph,par);
        if(cycle)
        {
            vector<int> ans;

            int x = cycle;
            ans.push_back(x);
            x = par[cycle];
            while(x != cycle)
            {
                ans.push_back(x);
                x = par[x];
            }

            ans.push_back(x);

            cout << ans.size() << '\n';
            for(int y : ans)
            {
                cout << y << ' ';
            }
            cout << '\n';
            return;
        }
    }

    cout << "IMPOSSIBLE\n";
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