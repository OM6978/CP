#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    vector<int> ar(N+1);
    for(int i=1;i<=N;i++)
    {
        cin>>ar[i];
    }

    map<int,vector<int>> neatHash;
    for(int i=1;i<=N;i++)
    {
        auto & vals = neatHash[ar[i]];
        vals.push_back(i);
    }

    // for(auto [hash,blocks] : neatHash)
    // {
    //     cout << hash << '\n';
    //     for(int a : blocks)
    //     {
    //         cout << a << ' ';
    //     }
    //     cout << "\n";
    // }

    vector<int> dp(N+2,0);
    dp[0] = 0;

    for(int i=1;i<=N;i++)
    {
        auto & ndinds = neatHash[ar[i]];
        int cin = lower_bound(ndinds.begin(),ndinds.end(),i) - ndinds.begin();
        int nxti = cin + ar[i] - 1;
        int nxt = (nxti < ndinds.size())?ndinds[nxti]:-1;

        if(nxt != -1)
            dp[nxt] = max(dp[i-1] + ar[i],dp[nxt]);
            
        dp[i] = max(dp[i-1],dp[i]);
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
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}