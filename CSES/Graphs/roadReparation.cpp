#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    int N,M;
    cin>>N>>M;

    vector<vector<pair<int,int>>> graph(N+1);
        
    for(int i=0;i<M;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
    
        graph[u].push_back({v,c});
        graph[v].push_back({u,c});
    }

    vector<int> vis(N+1,0);
    
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    pq.push({0,1});

    ll ans = 0;
    while(pq.size())
    {
        auto [c,u] = pq.top();
        pq.pop();

        if(vis[u])continue;

        vis[u] = 1;
        ans += c;

        for(auto [v,vc] : graph[u])
        {
            if(vis[v] == 0)
                pq.push({vc,v});
        }
    }

    for(int i=1;i<=N;i++)
    {
        if(vis[i] == 0)
        {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }

    cout << ans << '\n';
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