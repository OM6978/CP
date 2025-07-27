#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N,M;
    cin>>N>>M;

    vector<vector<int>> graph(N+1);
    
    for(int i=0;i<M;i++)
    {
        int u,v;
        cin>>u>>v;
    
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<vector<int>> dp(N,vector<int>());
    for(int i=0;i<N;i++)
    {
        dp[i].assign(graph[i].size(),1e9);
    }

    queue<int> q;
    q.push(1);

    for(int time=0;time<graph[1].size();time++)
    {
        dp[1][time] = time;
    }

    while(q.size())
    {
        int cnt = q.size();
        while(cnt--)
        {
            int top = q.front();
            q.pop();

            for(int )
        }
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