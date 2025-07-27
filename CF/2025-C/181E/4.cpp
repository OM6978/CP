#include <bits/stdc++.h>
using namespace std;

#define int long long

int MOD = 998244353;

int power(int x,int y,int p)
{
    int res = 1;
    while (y > 0)
    {
        if (y%2 == 1)
        res = (res*x)%p;

        y >>=1;
        x = (x*x)%p;
    }
    return res%p;
}

int modInverse(int x,int MOD)
{
    return power(x,MOD-2,MOD);
}

void solve()
{
    int N,M;
    cin>>N>>M;

    vector<vector<int>> segs(N);
    map<int,vector<int>,greater<int>> starthash;
    pair<int,int> noseg = {1,1};
    
    for(int i=0;i<N;i++)
    {
        int l,r,p,q;
        cin>>l>>r>>p>>q;

        segs[i] = {r,p,q};
        starthash[l].push_back(i);

        noseg.first = (noseg.first * (q - p))%MOD;
        noseg.second = (noseg.second * q)%MOD;
    }

    vector<pair<int,int>> dp(M+2,{0,1});
    
    dp[M+1] = noseg;
    for(auto [li,starts] : starthash)
    {
        auto & dpi = dp[li];
        for(int i : starts)
        {
            auto segv = segs[i];
            int ri = segv[0];
            int pi = segv[1];
            int qi = segv[2];
            
            int lq = ri+1;
            
            auto & dpq = dp[lq];
    
            pair<int,int> ass;
            ass.first = (pi * ((qi * dpq.first) % MOD))%MOD;
            ass.second = (qi * (((qi - pi) * dpq.second) % MOD))%MOD;

            dpi.first = ((dpi.first*ass.second)%MOD + (ass.first*dpi.second)%MOD)%MOD;
            dpi.second = (dpi.second*ass.second)%MOD;
        }
    }

    cout << (dp[1].first * modInverse(dp[1].second,MOD)) % MOD << '\n';
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