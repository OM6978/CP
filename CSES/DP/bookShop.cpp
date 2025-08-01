#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N,X;
    cin>>N>>X;

    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    vector<int> br(N);
    for(int i=0;i<N;i++)
    {
        cin>>br[i];
    }

    vector<vector<int>> dp(N+1,vector<int> (X+1,0));

    for(int i=N-1;i>=0;i--)
    {
        for(int cost=0;cost<=X;cost++)
        {
            dp[i][cost] = dp[i+1][cost];
            if(cost + ar[i] <= X)
                dp[i][cost] = max(dp[i][cost],dp[i+1][cost+ar[i]] + br[i]);
        }
    }

    cout << dp[0][0] << '\n';
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