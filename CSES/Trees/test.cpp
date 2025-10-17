#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5+1;
const int logN = 20;

int vals[maxN];
int height[maxN];
int depth[maxN];
int cpar[maxN];

void hdDfs(vector<vector<int>> & tree)
{
    stack<pair<int,int>> s;
    s.push({1,0});

    while(s.size())
    {
        auto [u,par] = s.top();

        depth[u] = depth[par] + 1;
        for(int v : tree[u])
        {
            if(v == par)continue;
    
            hdDfs(v,u,tree);
            height[u] = max(height[u],height[v] + 1);
        }

        s.pop();
    }
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

    for(int i=0;i<Q;i++)
    {
        int qt;
        cin>>qt;

        if(qt == 1)
        {
            int s,x;
            cin>>s>>x;
        }
        else
        {
            int a,b;
            cin>>a>>b;
        }
    }
    cout << '\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/CP/input-CSES.txt", "r", stdin);
        freopen("/home/om/Acads/CP/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    solve();

    return 0;
}