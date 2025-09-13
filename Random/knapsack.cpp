#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N,S;
    cin>>S>>N;

    vector<int> sz(N);
    vector<int> val(N);

    for(int i=0;i<N;i++)
    {
        cin >> sz[i] >> val[i];
    }

    vector<vector<int>> dp(N+1,vector<int> (S+1,0));
    for(int i=0;i<N;i++)
    {
        for(int s=0;s<=S;s++)
        {
            if(s>=sz[i])
                dp[i+1][s-sz[i]] = max(dp[i][s-sz[i]],dp[i][s] + val[i]);
                
            dp[i+1][s] = max(dp[i+1][s],dp[i][s]);
        }
    }

    // for(int i=1;i<=N;i++)
    // {
    //     for(int s=0;s<=S;s++)
    //     {
    //         cout << dp[i][s] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << *max_element(dp[N].begin(),dp[N].end()) << '\n';
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