#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    vector<int> ans;

    int d = 10;
    while(d < n)
    {
        int fac = d+1;
        if(n%fac == 0)
        {
            int x = n/fac;
            ans.push_back(x);
        }

        d*=10LL;
    }

    reverse(ans.begin(),ans.end());
    
    cout << ans.size() << '\n';
    for(int a : ans)
    {
        cout << a << ' ';
    }
    if(ans.size())cout << '\n';
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