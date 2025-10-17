#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 1;
int p[maxN];
int head[maxN];
int height[maxN];
int depth[maxN];
int hChild[maxN];

void dfs1(int u,int par,vector<vector<int>> & tree)
{
    depth[u] = depth[par] + 1;

    for(int v : tree[u])
    {
        if(v == par)continue;

        dfs1(v,u,tree);

        if(height[v] + 1 > height[u])
        {
            height[u] = height[v] + 1;
            hChild[u] = v;
        }
    }
}

void dfs2(int u,int par,vector<vector<int>> & tree)
{
    for(int v : tree[u])
    {
        if(v == par)continue;

        if(v == hChild[u])
        {
            p[v] = p[u];
            head[v] = head[u];
        }
        else
        {
            p[v] = u;
            head[v] = v;
        }

        dfs2(v,u,tree);
    }
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

    fill(depth,depth+N+1,-1);
    fill(height,height+N+1,0);
    fill(hChild,hChild+N+1,-1);
    
    dfs1(1,0,tree);

    p[1] = 1;
    head[1] = 1;
    dfs2(1,0,tree);

    for(int q=0;q<Q;q++)
    {
        int a,b;
        cin>>a>>b;

        while(p[a] != p[b])
        {
            if(depth[p[a]] > depth[p[b]])
            {
                a = p[a];
            }
            else
            {
                b = p[b];
            }
        }

        // cout << a << ' ' << b << '\n';

        if(head[a] == head[b])
        {
            cout << ((depth[a] > depth[b])?b:a) << '\n';
        }
        else cout << p[a] << '\n';
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