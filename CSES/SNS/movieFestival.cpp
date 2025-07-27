#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    vector<pair<int,int>> movies;
    for(int i=0;i<N;i++)
    {
        int s,n;
        cin>>s>>n;

        movies.push_back({s,n});
    }

    sort(movies.begin(),movies.end());

    auto comp = [](const pair<int,int> & p1,const pair<int,int> & p2) -> bool
    {
        return p1.first < p2.first;
    };

    vector<int> dp(N+1,0);
    for(int i=N-1;i>=0;i--)
    {
        auto [s,n] = movies[i];
        dp[i] = max(dp[i],dp[i+1]);
        
        int in = lower_bound(movies.begin(),movies.end(),make_pair(n,0),comp) - movies.begin();
        dp[i] = max(dp[i],dp[in] + 1);
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