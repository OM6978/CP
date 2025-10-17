#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string code;
    cin>>code;

    int N = code.size();

    int l = -1;

    string s;
    for(int i=1;i<N;i++)
    {
        if((s.size() == 0 || code[i] != s.back()) || code[i] == '2')
        {
            s.push_back(code[i]);
        }
        else
        {
            l = s.size() - 1;
            while(l>=0 && i<N && s[l] != '2' && code[i] != '2')
            {
                s.pop_back();
                l--;
                i++;
            }
        }
    }

    // cout << s << '\n';

    N = s.size();

    vector<vector<int>> intervals;
    
    int M = 0;
    int cinterval = 0;
    int cstart = -1;

    for(int a : s)
    {
        if(a == '2')
        {
            intervals.push_back({cinterval,cstart});

            M++;
            cinterval = 0;
            cstart = -1;
        }
        else
        {
            cstart = a;
            cinterval++;
        }
    }
    
    intervals.push_back({cinterval,cstart});

    vector<vector<int>> dp(N,vector<int>(2));

    // base case
    {
        int sz0r = intervals[0][0];;
        int pr = intervals[0][1];

        if(pr == -1)
        {
            dp[0] = {1,1};
        }
        
        dp[0][pr] = sz0r - 1;
        dp[0][1 - pr] = 1e8;
    }

    for(int i=1;i<M;i++)
    {
        int iszl0 = dp[i-1][0];
        int iszl1 = dp[i-1][1];

        int iszr = intervals[i][0];
        int pr = intervals[i][1];

        if(pr == -1)
        {
            dp[i][0] = iszl0 - 1;
            if(dp[i][0] < 0)dp[i][0] = 1;

            dp[i][1] = iszl1 - 1;
            if(dp[i][1] < 0)dp[i][1] = 1;
        }
        else
        {
            int pl = iszr&pr;
    
            dp[i][pr] = dp[i-1][pl] + iszr - 2;

        }
    }
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/CP/input.txt", "r", stdin);
        freopen("/home/om/Acads/CP/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}