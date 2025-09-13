#include <bits/stdc++.h>
using namespace std;

#define int long long

int MOD = 998244353;

int power(int x, int y, int p)
{
    int res = 1;
    while (y > 0)
    {
        if (y % 2 == 1)
        res = (res * x)%p;

        y = y >> 1;
        x = (x * x) % p;
    }
    return res % p;
}

int modInverse(int x)
{
    return power(x,MOD-2,MOD);
}

void solve()
{
    int N,M;
    cin>>N>>M;

    vector<tuple<int,int,int>> segs(N);
    vector<pair<int,int>> begins(N);
    pair<int,int> noseg = {1,1};

    for(int i=0;i<N;i++)
    {
        int l,r,p,q;
        cin>>l>>r>>p>>q;

        segs[i] = {r,p,q};
        begins[i] = {l,i};

        noseg.first = (noseg.first * (q - p)) % MOD;
        noseg.second = (noseg.second * q) % MOD;
    }

    sort(begins.begin(),begins.end());

    vector<pair<int,int>> dp(M+2,make_pair(0,1));
    dp[M+1] = noseg;

    for(int i=N-1;i>=0;i--)
    {
        auto [l,sin] = begins[i];
        auto [r,p,q] = segs[sin];

        pair<int,int> fwprob;
        fwprob.first = (dp[r+1].first * ((q * p) % MOD))%MOD;
        fwprob.second = (dp[r+1].second * (((q - p) * q) % MOD))%MOD;

        dp[l].first = ((dp[l].first * fwprob.second)%MOD + (dp[l].second * fwprob.first)%MOD) % MOD;
        dp[l].second = (dp[l].second * fwprob.second) % MOD;
    }

    cout << (dp[1].first * modInverse(dp[1].second)) % MOD << '\n';
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