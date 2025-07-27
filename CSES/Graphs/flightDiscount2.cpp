#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N,M;
    cin>>N>>M;
    
    vector<vector<pair<int,int>>> graph(N+1);
    vector<pair<pair<int,int>,int>> edges;
    
    for(int i=0;i<M;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;

        graph[u].push_back({v,c});
        edges.push_back({{u,v},c});
    }

    vector<pair<int,int>> dp(N+1,{1e15,1e15});

    dp[1] = {0,0};

    for(int i=0;i<N;i++)
    {
        for(auto [p,c] : edges)
        {
            auto [u,v] = p;
            dp[v].first = min(dp[v].first,dp[u].first + c);
            dp[v].second = min(dp[v].second,dp[u].first + c/2);
            dp[v].second = min(dp[v].second,dp[u].second + c);
        }
    }

    cout << min(dp[N].first,dp[N].second) << '\n';
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