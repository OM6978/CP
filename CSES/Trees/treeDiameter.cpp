#include <bits/stdc++.h>
using namespace std;

pair<int,int> dia(int u,int par,vector<vector<int>> & tree)
{
    pair<int,int> du = {1,0};

    int h1=0,h2=0;
    for(int v : tree[u])
    {
        if(v != par)
        {
            auto [h,d] = dia(v,u,tree);
            if(h >= h1)
            {
                h2 = h1;
                h1 = h;
            }
            else h2 = max(h,h2);

            du.second = max(du.second,d);
        }
    }

    du.first = h1 + 1;
    du.second = max(du.second,h1 + h2);

    return du;
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

    cout << dia(1,-1,tree).second << '\n';
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