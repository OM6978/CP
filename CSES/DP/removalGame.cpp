#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxN = 5002;
int dp[maxN][maxN][2] = {0};

void solve()
{
    int N;
    cin>>N;
    
    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    for(int gap=1;gap<=N;gap++)
    {
        for(int i=0;i+1+gap<=N+1;i++)
        {
            dp[i][i+1+gap][0] = dp[i+1][i+1+gap][1] + ar[i];
            dp[i][i+1+gap][1] = dp[i+1][i+1+gap][0];

            dp[i][i+1+gap][0] = max(dp[i][i+1+gap][0],dp[i][i+gap][1] + ar[i+gap-1]);
            dp[i][i+1+gap][1] = min(dp[i][i+1+gap][1],dp[i][i+gap][0]);
        }
    }

    cout << dp[0][N+1][0] << '\n';
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