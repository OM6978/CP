#include <bits/stdc++.h>
using namespace std;

void dfs(int u,int par,vector<vector<int>> & tree,int & timer,vector<int> & in,vector<int> & out)
{
    in[u] = timer;
    timer++;
    
    for(int v : tree[u])
    {
        if(v == par)continue;

        dfs(v,u,tree,timer,in,out);
    }

    out[u] = timer;
}

bool good(int time,int l,int r,vector<int> & nodeInstances,vector<int> & out)
{
    int u = nodeInstances[time];
    int fu = out[u];

    bool c0 = (time <= l);
    bool c1 = c0 && (fu >= r);
    bool c2 = c0 && (fu <= l);

    return c1 || c2;
}

void solve()
{
    int N,Q;
    cin>>N>>Q;

    vector<vector<int>> tree(N+1);
    for(int u=2;u<=N;u++)
    {
        int p;
        cin>>p;

        tree[u].push_back(p);
        tree[p].push_back(u);
    }

    int timer = 0;
    vector<int> in(N+1);
    vector<int> out(N+1);

    dfs(1,0,tree,timer,in,out);

    vector<int> nodeInstances(N+1);

    for(int u=1;u<=N;u++)
    {
        nodeInstances[in[u]] = u;
    }

    for(int u=1;u<=N;u++)
    {
        cout << in[u] << ' ' << out[u] << '\n';
    }

    while(Q--)
    {
        int a,b;
        cin>>a>>b;

        int lin = min(in[a],in[b]);
        int rout = max(out[a],out[b]);

        int l = 0,r = timer+1;
        while(l + 1 < r)
        {
            int mid = (l+r)>>1;
            if(good(mid,lin,rout,nodeInstances,out))l = mid;
            else r = mid;

            // cout << mid << ' ';
        }

        cout << nodeInstances[l] << '\n';
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