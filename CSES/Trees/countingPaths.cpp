#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5+1;
const int logN = 20;
int Bul[maxN][logN];

void assignPar(int u,int par,vector<vector<int>> & tree)
{
    Bul[u][1] = par;
    Bul[u][0] = u;

    for(int v : tree[u])
    {
        if(v == par)continue;

        assignPar(v,u,tree);
    }
}

void getDepth(int u,int par,vector<vector<int>> & tree,vector<int> & depth)
{
    depth[u] = depth[par] + 1;
    for(int v : tree[u])
    {
        if(v == par)continue;

        getDepth(v,u,tree,depth);
    }
}

void assignPath(int oa,int ob,int lca,vector<int> & Paths)
{
    Paths[oa]++;
    Paths[ob]++;

    Paths[lca]--;
    Paths[Bul[lca][1]]--;
}

void computePaths(int u,int par,vector<vector<int>> & tree,vector<int> & Paths)
{
    for(int v : tree[u])
    {
        if(v == par)continue;

        computePaths(v,u,tree,Paths);
        Paths[u] += Paths[v];
    }
}

void solve()
{
    int N,M;
    cin>>N>>M;

    vector<vector<int>> tree(N+1);
    
    for(int i=0;i<N-1;i++)
    {
        int u,v;
        cin>>u>>v;
    
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    for(int i=0;i<logN;i++)
    {
        Bul[0][i] = 0;
    }
    
    assignPar(1,0,tree);

    for(int k=2;k<logN;k++)
    {
        for(int u=1;u<=N;u++)
        {
            Bul[u][k] = Bul[Bul[u][k-1]][k-1];
        }
    }

    vector<int> depth(N+1,0);
    getDepth(1,0,tree,depth);

    vector<int> Paths(N+1,0);

    for(int i=0;i<M;i++)
    {
        int a,b;
        cin>>a>>b;

        int oa = a;
        int ob = b;

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
                b = Bul[b][k+1];
            }
        }

        auto good = [](int k,int a,int b) -> bool
        {
            return Bul[a][k] == Bul[b][k];
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
                int l = 0,r = logN -1;
                while(l+1<r)
                {
                    int mid = (l+r)>>1;
                    if(good(mid,a,b))r = mid;
                    else l = mid;
                }
    
                if(r==1)break;
    
                a = Bul[a][l];
                b = Bul[b][l];
            }
    
            lca = Bul[a][1];
        }

        assignPath(oa,ob,lca,Paths);

        // cout << lca << '\n';
    }

    // for(int u=1;u<=N;u++)
    // {
    //     cout << Paths[u] << ' ';
    // }
    // cout << '\n';

    computePaths(1,0,tree,Paths);


    for(int u=1;u<=N;u++)
    {
        cout << Paths[u] << ' ';
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