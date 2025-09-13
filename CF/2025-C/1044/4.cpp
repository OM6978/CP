#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N;
    cin>>N;

    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    vector<vector<int>> dp(N+1,vector<int> (3));

    dp[0][0] = ar[0];
    dp[0][1] = ar[0];
    dp[0][2] = ar[0];

    for(int i=1;i<N;i++)
    {
        dp[i][0] = dp[i-1][2] + max(ar[i] - i,0LL);
        dp[i][1] = min(dp[i-1][0],dp[i-1][1]) + ar[i] - 1;
        dp[i][2] = min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2]) + ar[i];
    }

    cout << *min_element(dp[N-1].begin(),dp[N-1].end()) << '\n';
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