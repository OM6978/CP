#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll MOD = 1e9 + 7;

void track(int u,vector<vector<int>> & graph,vector<int> & vis)
{
    if(vis[u])return;

    vis[u] = 1;

    for(int v : graph[u])
    {
        track(v,graph,vis);
    }
}

void solve()
{
    int N,M;
    cin>>N>>M;

    vector<vector<int>> graph(N+1,vector<int>());
    for(int i=0;i<M;i++)
    {
        int u,v;
        cin>>u>>v;

        graph[u].push_back(v);
    }

    vector<int> vis(N+1,0);
    track(1,graph,vis);

    vector<int> indeg(N+1,0);
    for(int u=1;u<=N;u++)
    {
        if(vis[u] == 0)continue;

        for(int v : graph[u])
        {
            indeg[v]++;
        }
    }

    queue<int> q;
    for(int u=1;u<=N;u++)
    {
        if(vis[u] != 0 && indeg[u] == 0)
        {
            q.push(u);
        }

        // cout << vis[u] << ' ';
    }
    // cout << '\n';

    vector<ll> dp(N+1,0LL);
    dp[1] = 1LL;

    while(q.size())
    {
        int cnt = q.size();
        while(cnt--)
        {
            int u = q.front();
            q.pop();

            for(int v : graph[u])
            {
                dp[v] = (dp[v] + dp[u])%MOD;

                indeg[v]--;
                if(indeg[v] == 0)
                {
                    q.push(v);
                }
            }
        }
    }

    cout << dp[N] << '\n';
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