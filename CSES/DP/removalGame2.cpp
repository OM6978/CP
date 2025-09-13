#include <bits/stdc++.h>
using namespace std;

#define int long long

int solvedp(int turn,int l,int r,vector<int> & ar,vector<vector<int>> & dp)
{
    if(l > r)return 0;
    if(dp[l][r] != -1e15)return dp[l][r];

    if(turn)
    {
        return dp[l][r] = min(solvedp(0,l+1,r,ar,dp),solvedp(0,l,r-1,ar,dp));
    }
    else
    {
        return dp[l][r] = max(solvedp(1,l+1,r,ar,dp) + ar[l],solvedp(1,l,r-1,ar,dp) + ar[r]);
    }
}

void solve()
{
    int N;
    cin>>N;

    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    vector<vector<int>> dp(N+1,vector<int> (N+1,-1e15));

    cout << solvedp(0,0,N-1,ar,dp) << '\n';
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