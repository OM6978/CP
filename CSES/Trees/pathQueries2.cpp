#include <bits/stdc++.h>
using namespace std;

const int nullval = 0;
int getOp(int x,int y){return max(x,y);}

int getSTOp(vector<int> & st,int l,int r,int x,int lx,int rx)
{
    if(lx >= r || rx <= l)return nullval;
    if(lx >= l && rx <= r)return st[x];

    int mid = (lx+rx)>>1;
    int res1 = getSTOp(st,l,r,2*x+1,lx,mid);
    int res2 = getSTOp(st,l,r,2*x+2,mid,rx);
    return getOp(res1,res2);
}

int getSTWrapper(vector<int> & st,int l,int r)
{
    return getSTOp(st,l,r,0,0,(st.size()+1)/2);
}

void setSTVal(vector<int> & st,int l,int r,int x,int lx,int rx,int val)
{
    if(rx <= l || lx >= r)return;
    if(lx + 1 < rx)
    {
        int mid = (lx + rx)>>1;
        setSTVal(st,l,r,2*x+1,lx,mid,val);
        setSTVal(st,l,r,2*x+2,mid,rx,val);

        st[x] = getOp(st[2*x+1],st[2*x+2]);
    }
    else st[x] = val;
}

void setSTWrapper(vector<int> & st,int i,int val)
{
    setSTVal(st,i,i+1,0,0,(st.size()+1)/2,val);
}

vector<int> initST(vector<int> & ar)
{
    int N = ar.size();
    int sz = 1;
    while(sz<N)sz<<=1;

    vector<int> st(2*sz-1,nullval);
    for(int i=0;i<N;i++)
        setSTWrapper(st,i,ar[i]);

    return st;
}

const int maxN = 2e5+1;
const int logN = 20;

int vals[maxN];
int height[maxN];
int depth[maxN];
int cpar[maxN];

void hdDfs(int u,int par,vector<vector<int>> & tree)
{
    depth[u] = depth[par] + 1;
    for(int v : tree[u])
    {
        if(v == par)continue;

        hdDfs(v,u,tree);
        height[u] = max(height[u],height[v] + 1);
    }
}

void dfs(int u,int par,vector<vector<int>> & tree,vector<pair<int,int>> & clusterHash,vector<vector<int>> & clusters)
{
    int most = -1;
    for(int v : tree[u])
    {
        if(v == par)continue;

        if(most == -1 || height[most] < height[v])
        {
            most = v;
        }
    }

    for(int v : tree[u])
    {
        if(v == par)continue;

        if(v != most)
        {
            cpar[clusters.size()] = u;
            clusterHash[v] = {clusters.size(),0};
            clusters.push_back({vals[v]});
        }
        else
        {
            int ucluster = clusterHash[u].first;

            clusterHash[v] = {ucluster,clusters[ucluster].size()};
            clusters[ucluster].push_back(vals[v]);
        }

        dfs(v,u,tree,clusterHash,clusters);
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

int getLCA(int a,int b,vector<vector<int>> & tree,vector<vector<int>> & blpars)
{
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

    if(a==b)
    {
        return a;
    }

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

    return blpars[a][0];
}

int pPathMax(int u,int p,vector<vector<int>> & clST,vector<pair<int,int>> & clusterHash)
{
    int most = 0;
    while(u!=p)
    {
        int du = depth[u];
        int dp = depth[p];
    
        auto [uc,ucin] = clusterHash[u];

        int lift = du - dp;

        auto & ust = clST[uc];
        if(ucin - lift >= 0)
        {
            most = max(getSTWrapper(ust,ucin - lift,ucin+1),most);
            u = p;
        }
        else
        {
            most = max(getSTWrapper(ust,0,ucin+1),most);
            u = cpar[uc];
        }
    }

    return most;
}

void solve()
{
    int N,Q;
    cin>>N>>Q;
    
    vector<int> vals(N+1);
    for(int u=1;u<=N;u++)
    {
        cin>>vals[u];
    }

    vector<vector<int>> tree(N+1,vector<int> ());

    for(int i=0;i<N-1;i++)
    {
        int u,v;
        cin>>u>>v;
    
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    depth[0] = 0;
    height[0] = 0;
    cpar[0] = 0;

    hdDfs(1,0,tree);

    vector<vector<int>> clusters;
    vector<pair<int,int>> clusterHash(N+1);

    clusters.push_back({vals[1]});
    clusterHash[1] = {0,0};

    dfs(1,0,tree,clusterHash,clusters);

    for(int i=0;i<clusters.size();i++)
    {
        auto & cluster = clusters[i];

        // cout << cpar[i] << " - ";
        // for(int val : cluster)
        // {
        //     cout << val << ' ';
        // }
        // cout << '\n';
    }
    // cout << '\n';

    vector<vector<int>> blpars(N+1,vector<int>(logN,-1));

    for(int v : tree[1])
    {
        blassign(v,1,tree,blpars);
    }

    int M = clusters.size();
    vector<vector<int>> clST(M);
    for(int i=0;i<M;i++)
    {
        clST[i] = initST(clusters[i]);
    }

    for(int i=0;i<Q;i++)
    {
        int qt;
        cin>>qt;

        if(qt == 1)
        {
            int s,x;
            cin>>s>>x;

            auto [cl,cind] = clusterHash[s];
            setSTWrapper(clST[cl],cind,x);

            vals[s] = x;
        }
        else
        {
            int a,b;
            cin>>a>>b;

            int lca = getLCA(a,b,tree,blpars);

            // cout << lca << ' ';
            // cout << vals[lca] << ' ';
            // cout << a << ' ' << b << '\n';

            int m1 = pPathMax(a,lca,clST,clusterHash);
            int m2 = pPathMax(b,lca,clST,clusterHash);

            // cout << m1 << ' ' << m2 << '\n';
            // cout << '\n';

            cout << max(max(m1,m2),vals[lca]) << ' ';
        }
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