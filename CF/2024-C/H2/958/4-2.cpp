#include <bits/stdc++.h>
using namespace std;

#define int long long

int treeSum(int u,int par,vector<vector<int>> & tree,vector<int> & hitPoints)
{
    int res = 0;
    for(int v : tree[u])
    {
        if(v == par)continue;

        res += treeSum(v,u,tree,hitPoints);
    }

    return res + hitPoints[u];
}

void killMostMonsters(int u,int par,vector<vector<int>> & tree,vector<int> & hitPoints,vector<pair<int,int>> & dp,vector<pair<int,int>> & child)
{
    for(int v : tree[u])
    {
        if(v == par)continue;

        killMostMonsters(v,u,tree,hitPoints,dp,child);

        dp[u].first += dp[v].second;
        dp[u].second += max(dp[v].first,dp[v].second);

        child[u].first = v;
        child[u].second = 
    }

    dp[u].first += hitPoints[u];
}

void solve()
{
    int N;
    cin>>N;

    vector<int> hitPoints(N+1);

    for(int i=1;i<=N;i++)
    {
        cin>>hitPoints[i];
    }

    vector<vector<int>> tree(N+1);
    
    for(int i=0;i<N-1;i++)
    {
        int u,v;
        cin>>u>>v;
    
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int currHits = 0;
    while(treeSum(1,0,tree,hitPoints) > currHits)
    {

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
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}