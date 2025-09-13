#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
void solve()
{
    string as,bs;
    cin>>as>>bs;
 
    vector<int> av;
    vector<int> bv;
 
    transform(as.begin(), as.end(), back_inserter(av),[](char c) { return c - '0'; });
    transform(bs.begin(), bs.end(), back_inserter(bv),[](char c) { return c - '0'; });
 
    int dp[19][10][2][2] = {0LL};
 
    int diff = bv.size() - av.size();
    vector<int> padding(diff,0);
    av.insert(av.begin(),padding.begin(),padding.end());
 
    for(int i=0;i<diff;i++)
    {
        dp[i][0][1][0] = 1;
    }
    
    int N = bv.size();
    for(int j=0;j<10;j++)
    {
        int l = av[0];
        int r = bv[0];
 
        if(j >= l && j <= r)
        {
            if(j == l && j==r)
            {
                dp[0][j][1][1] = 1;
            }
            else if(j == l)
            {
                dp[0][j][1][0] = 1;
            }
            else if(j == r)
            {
                dp[0][j][0][1] = 1;
            }
            else
            {
                dp[0][j][0][0] = 1;
            }
        }
    }
 
    for(int i=1;i<N;i++)
    {
        int l = av[i];
        int r = bv[i];

        for(int j=0;j<10;j++)
        {
            for(int k=0;k<10;k++)
            {
                if(k!=j)
                {
                    dp[i][j][0][0] += dp[i-1][k][0][0];
 
                    if(j == l && j == r)
                    {
                        dp[i][j][1][1] += dp[i-1][k][1][1];
                        dp[i][j][0][1] += dp[i-1][k][0][1];
                        dp[i][j][1][0] += dp[i-1][k][1][0];
                    }
                    else if(j == l)
                    {
                        dp[i][j][1][0] += dp[i-1][k][1][0] + dp[i-1][k][1][1];
                    }
                    else if(j == r)
                    {
                        dp[i][j][0][1] += dp[i-1][k][0][1] + dp[i-1][k][1][1];
                    }
 
                    if(j > l && j < r)
                    {
                        dp[i][j][0][0] += dp[i-1][k][1][1];
                    }
 
                    if(j < r)
                    {
                        dp[i][j][0][0] += dp[i-1][k][0][1];
                    }
 
                    if(j > l)
                    {
                        dp[i][j][0][0] += dp[i-1][k][1][0];
                    }
                }
            }
        }
    }
 
    int ans = 0;
    for(int j=0;j<10;j++)
    {
        ans += dp[N-1][j][0][0] + dp[N-1][j][0][1] + dp[N-1][j][1][0] + dp[N-1][j][1][1];
    }

    if(as == "0" && bs.size() > 1)ans++;
 
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