#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N,X;
    cin>>N>>X;

    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    vector<pair<int,int>> dp((1<<N),{1e14,1e14});
    dp[0] = {0,0};
    for(int take = 0;take < (1<<N);take++)
    {
        for(int i=0;i<N;i++)
        {
            int dpin = (1<<i);
            if(take & dpin)
            {
                auto [cans,last] = dp[take^dpin];
                if(last + ar[i] <= X)
                {
                    last += ar[i];
                }
                else
                {
                    cans++;
                    last = ar[i];
                }

                dp[take] = min(dp[take],{cans,last});
            }
        }
    }

    cout << dp[(1<<N) - 1].first + (dp[(1<<N) - 1].second > 0) << '\n';
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