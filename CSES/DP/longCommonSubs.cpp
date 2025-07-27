#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N,M;
    cin>>N>>M;

    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    vector<int> br(M);
    for(int i=0;i<M;i++)
    {
        cin>>br[i];
    }

    vector<vector<int>> dp(N+1,vector<int> (M+1,0));
    vector<vector<pair<int,int>>> par(N+1,vector<pair<int,int>> (M+1,{-1,-1}));

    for(int i=N-1;i>=0;i--)
    {
        for(int j=M-1;j>=0;j--)
        {
            if(ar[i] == br[j])
            {
                dp[i][j] = dp[i+1][j+1] + 1;
                par[i][j] = {i,j};
            }
            else
            {
                dp[i][j] = dp[i][j+1];

                if(dp[i+1][j] > dp[i][j])par[i][j] = par[i+1][j];
                else par[i][j] = par[i][j+1];

                dp[i][j] = max(dp[i][j],dp[i+1][j]);
            }
        }
    }

    vector<int> ans;
    pair<int,int> curr = par[0][0];
    while(curr!=make_pair(-1,-1))
    {
        ans.push_back(ar[curr.first]);
        curr = par[curr.first+1][curr.second+1];
    }

    cout << dp[0][0] << '\n';
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