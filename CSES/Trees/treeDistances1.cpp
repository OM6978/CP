#include <bits/stdc++.h>
using namespace std;

void dfs(int u,int mpdist,int par,vector<pair<int,int>> & dists,vector<int> & dinds,vector<vector<int>> & tree,vector<int> & res)
{
    res[u] = max(mpdist,dists[u].first);
    int mi = dinds[u];

    for(int v : tree[u])
    {
        if(v == par)continue;

        if(mi == v)
        {
            dfs(v,max(dists[u].second,mpdist)+1,u,dists,dinds,tree,res);
        }
        else
        {
            dfs(v,max(dists[u].first,mpdist)+1,u,dists,dinds,tree,res);
        }
    }
}

void solve()
{
    int N;
    cin>>N;

    vector<vector<int>> tree(N+1);
    
    for(int i=0;i<N-1;i++)
    {
        int u,v;
        cin>>u>>v;
    
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<pair<int,int>> dists(N+1);
    vector<int> dinds(N+1);

    auto hght = [&](int u,int par,auto && hght) -> int
    {
        int most = 0, smost = 0;
        int mind = 0;

        for(int v : tree[u])
        {
            if(v == par)continue;

            int h = hght(v,u,hght) + 1;
            if(most < h)
            {
                smost = most;
                most = h;

                mind = v;
            }
            else if(smost < h)
            {
                smost = h;
            }
        }

        dists[u] = {most,smost};
        dinds[u] = mind;

        return most;
    };

    hght(1,-1,hght);

    vector<int> res(N+1,0);

    dfs(1,0,-1,dists,dinds,tree,res);

    for(int i=1;i<=N;i++)
    {
        cout << res[i] << ' ';
    }
    cout << '\n';
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