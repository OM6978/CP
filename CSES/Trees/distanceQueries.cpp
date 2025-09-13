#include <bits/stdc++.h>
using namespace std;

const int logN = 20;

void ndepth(int u,int par,int dpar,vector<vector<int>> & tree,vector<int> & depth)
{
    depth[u] = dpar;
    for(int v : tree[u])
    {
        if(v== par)continue;

        ndepth(v,u,dpar+1,tree,depth);
    }
}

void blassign(int u,int par,vector<vector<int>> & tree,vector<vector<int>> & blpars)
{
    blpars[u][0] = par;
    for(int p=1;p<logN;p++)
    {
        if(blpars[u][p-1] == -1)break;

        blpars[u][p] = blpars[blpars[u][p-1]][p-1];
    }

    for(int v : tree[u])
    {
        if(v == par)continue;

        blassign(v,u,tree,blpars);
    }
}

void solve()
{
    int N,Q;
    cin>>N>>Q;

    vector<vector<int>> tree(N+1);

    for(int i=0;i<N-1;i++)
    {
        int u,v;
        cin>>u>>v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> depth(N+1,0);
    ndepth(1,-1,0,tree,depth);

    vector<vector<int>> blpars(N+1,vector<int>(logN,-1));

    for(int v : tree[1])
    {
        blassign(v,1,tree,blpars);
    }

    while(Q--)
    {
        int a,b;
        cin>>a>>b;

        int d1 = depth[a];
        int d2 = depth[b];

        if(d2 < d1)
        {
            swap(a,b);
            swap(d2,d1);
        }

        int lift = d2 - d1;
        for(int k=0;k<logN;k++)
        {
            if(lift & (1<<k))
            {
                b = blpars[b][k];
            }
        }

        auto good = [](int k,vector<int> & aps,vector<int> & bps) -> bool
        {
            return aps[k] == bps[k];
        };

        int lca;
        if(a==b)
        {
            lca = a;
        }
        else
        {
            while(true)
            {
                int l = -1,r = logN -1;
                while(l+1<r)
                {
                    int mid = (l+r)>>1;
                    if(good(mid,blpars[a],blpars[b]))r = mid;
                    else l = mid;
                }
    
                if(r==0)break;
    
                a = blpars[a][l];
                b = blpars[b][l];
            }
    
            lca = blpars[a][0];
        }

        cout << d1 + d2 - 2*depth[lca] << '\n';
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