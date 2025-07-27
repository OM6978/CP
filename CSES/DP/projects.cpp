#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
int bs(vector<pair<int,int>> & start,int val)
{
    int N = start.size();
    int l=0,r=N;
    while(l+1<r)
    {
        int mid = (l+r)>>1;
        if(start[mid].first <= val)l = mid;
        else r = mid;
    }
 
    return r;
}
 
void solve()
{
    int N;
    cin>>N;
 
    vector<pair<int,int>> meets(N);
    vector<pair<int,int>> start(N);
    vector<int> rew(N);
    for(int i=0;i<N;i++)
    {
        int a,b,p;
        cin>>a>>b>>p;
 
        meets[i] = {a,b};
        rew[i] = p;
 
        start[i] = {a,i};
    }
 
    sort(start.begin(),start.end());
 
    vector<int> dp(N,0);
    for(int i=N-1;i>=0;i--)
    {
        int orin = start[i].second;
        auto [arr,dep] = meets[orin];
 
        int in2 = bs(start,dep);
        
        if(in2 < N)dp[i] = max(dp[i],rew[orin] + dp[in2]);
        else dp[i] = max(dp[i],rew[orin]);
 
        if(i < N-1)dp[i] = max(dp[i],dp[i+1]);
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