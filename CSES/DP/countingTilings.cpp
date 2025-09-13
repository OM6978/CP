#include <bits/stdc++.h>
using namespace std;

#define int long long

int MOD = 1e9 + 7;

void rec(int i,int ways,int layer,int nlayer,vector<int> & dp,int N)
{
    if(i == N)
    {
        dp[nlayer] = (dp[nlayer] + ways)%MOD;
    }
    else if((layer&(1<<i)) > 0)
    {
        rec(i+1,ways,layer,nlayer,dp,N);
    }
    else
    {
        if(i < N-1 && (layer&(1<<i)) == 0 && (layer&(1<<(i+1))) == 0)
        {
            rec(i+2,ways,layer,nlayer,dp,N);
        }
    
        nlayer += (1<<i);
        rec(i+1,ways,layer,nlayer,dp,N);
        nlayer -= (1<<i);
    }
}

void solve()
{
    int N,M;
    cin>>N>>M;

    int dpsz = (1<<N);
    vector<int> dp(dpsz,0);
    vector<int> dpit(dpsz,0);

    dp[0] = 1;

    for(int i=0;i<M;i++)
    {
        for(int j=0;j<dpsz;j++)
        {
            rec(0,dp[j],j,0,dpit,N);
        }

        dp = dpit;
        dpit.assign(dpsz,0LL);
    }

    cout << dp[0] << '\n';
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