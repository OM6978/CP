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

    int sz = 1000*N+1;
    vector<int> prevdp(sz,0),dp(sz,0);

    prevdp[0] = 1;
    int sum = 0;
    for(int i=0;i<N;i++)
    {
        for(int s=0;s<=sum;s++)
        {
            if(prevdp[s])
            {
                dp[s] = 1;
                dp[s+ar[i]] = 1;
            }
        }
        sum+=ar[i];

        for(int i=0;i<sz;i++)
        {
            prevdp[i] = dp[i];
            dp[i] = 0;
        }
    }

    vector<int> ans;
    for(int i=1;i<sz;i++)
    {
        if(prevdp[i])
        {
            ans.push_back(i);
        }
    }

    cout << ans.size() << '\n';
    for(int a : ans)
    {
        cout << a << ' ';
    }
    cout << '\n';
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