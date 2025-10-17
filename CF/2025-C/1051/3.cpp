#include <bits/stdc++.h>
using namespace std;

void assignPerm(int u,int par,vector<vector<pair<int,pair<int,int>>>> & tree,vector<int> & p,int & l,int & r)
{
    for(auto [v,vals] : tree[u])
    {
        if(v == par)continue;

        assignPerm(v,u,tree,p,l,r);
        auto [x,y] = vals;

        if(x > y)
        {
            if(v < u)p[v] = r--;
            else p[v] = l++;
        }
        else
        {
            if(v < u)p[v] = l++;
            else p[v] = r--;
        }
    }
}

void solve()
{
    int N;
    cin>>N;

    vector<vector<pair<int,pair<int,int>>>> tree(N+1);
    
    for(int i=0;i<N-1;i++)
    {
        int u,v,x,y;
        cin>>u>>v>>x>>y;
    
        tree[u].push_back({v,{x,y}});
        tree[v].push_back({u,{x,y}});
    }

    tree[0].push_back({1,{0,0}});

    vector<int> p(N+1);
    int l=1,r=N;
    assignPerm(0,-1,tree,p,l,r);

    for(int i=1;i<=N;i++)
    {
        cout << p[i] << ' ';
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
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}