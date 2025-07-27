#include <bits/stdc++.h>
using namespace std;

#define int long long 

int MOD = 1e9 + 7;

void solve()
{
    int N,M;
    cin>>N>>M;

    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    vector<vector<int>> dp(N,vector<int> (M+1,0));

    for(int i=1;i<=M;i++)
    {
        dp[0][i] = (ar[0] == 0 || i==ar[0]);
    }

    for(int i=1;i<N;i++)
    {
        for(int val=1;val<=M;val++)
        {
            if(ar[i] == val || ar[i] == 0)
            {
                dp[i][val] = dp[i-1][val];
                if(val - 1 >= 1)
                    dp[i][val] += dp[i-1][val-1];
                if(val + 1 <= M)
                    dp[i][val] += dp[i-1][val+1];

                dp[i][val] %= MOD;
            }
        }
    }

    int ans = 0;
    for(int i=1;i<=M;i++)
    {
        ans = (ans + dp[N-1][i])%MOD;
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