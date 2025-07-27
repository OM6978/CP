#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    int val = ar[0];
    for(int i=1;i<N;i++)
    {
        val = __gcd(ar[i],val);
    }

    int nums = 0;
    for(int i=0;i<N;i++)
    {
        if(ar[i] == val)nums++;
    }

    vector<int> dp(5001,1e4);
    dp[ar[N-1]] = 0;
    for(int i=N-2;i>=0;i--)
    {
        for(int j=1;j<=5000;j++)
        {
            int g = __gcd(ar[i],j);
            dp[g] = min(dp[g],dp[j] + 1);
            dp[j] = min(dp[j],dp[j]);
        }
        dp[ar[i]] = 0;
    }

    cout << ((nums==0)?dp[val] + N - 1: N - nums) << '\n';
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