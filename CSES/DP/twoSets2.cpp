#include <bits/stdc++.h>
using namespace std;

#define int long long

int maxN = 501;
int MOD = 1e9 + 7;

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

void solve()
{
    int N;
    cin>>N;

    int sz = (maxN*(maxN+1))/2 + 1;

    vector<int> prevdp(sz,1),dp(sz,0);
    
    int sum = 0;
    for(int num=1;num<=N;num++)
    {
        for(int s=0;s<=sum;s++)
        {
            dp[s+num] = (dp[s+num] + prevdp[s])%MOD;
            dp[abs(s-num)] = (dp[abs(s-num)] + prevdp[s])%MOD;
        }
        sum += num;

        for(int i=0;i<sz;i++)
        {
            prevdp[i] = dp[i];
            dp[i] = 0;
        }
    }

    cout << (prevdp[0]*power(2LL,MOD-2,MOD))%MOD << '\n';
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