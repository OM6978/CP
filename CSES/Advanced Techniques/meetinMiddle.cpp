#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int ways(int k,ll x,vector<int> & ar)
{
    ll s = 0;
    for(int i=0;i<k;i++)
    {
        s += ar[i];
    }

    int res = 0;
    if(s == x)res++;

    int n = ar.size();
    for(int i=k;i<n;i++)
    {
        s += (ll)ar[i];
        s -= (ll)ar[i-k];

        if(s==x)res++;
    }

    return res;
}

void solve()
{
    int N,X;
    cin>>N>>X;

    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    int ans = 0;
    for(int k=N;k>0;k--)
    {
        ans += ways(k,X,ar);
    }

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