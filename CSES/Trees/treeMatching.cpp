#include <bits/stdc++.h>
using namespace std;
 
void solvedp(int u,int par,vector<vector<int>> & tree,vector<pair<int,int>> & dp)
{
    int zeroSum = 0;
    int most = -1;
    for(int v : tree[u])
    {
        if(v != par)
        {
            solvedp(v,u,tree,dp);
            if(most == -1)
                most = v;
            else if(dp[v].second - dp[v].first + dp[most].first - dp[most].second > 0)
            {
                most = v;
            }
            zeroSum += dp[v].first;
        }
    }
 
    dp[u].second = zeroSum;
    dp[u].first = zeroSum;
    
    if(most!=-1)
        dp[u].first = max(zeroSum + dp[most].second - dp[most].first + 1,zeroSum);
}
 
void solve()
{
    int N;
    cin>>N;
 
    vector<vector<int>> tree(N+1);
    
    for(int i=0;i<N-1;i++)
    {
        int u,v;
        cin>>u>>v;
    
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
 
    vector<pair<int,int>> dp(N+1,{0,0});
    solvedp(1,-1,tree,dp);

    cout << max(dp[1].first,dp[1].second) << '\n';
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