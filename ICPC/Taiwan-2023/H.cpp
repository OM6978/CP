#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll logceil(ll n)
{
    ll lgn = log2(n);
    if((1LL<<lgn) != n)lgn++;

    return lgn;
}

void solve()
{
    ll n,k;
    cin>>n>>k;

    ll th = logceil(n+1);
    ll tfh = th - 1;

    ll ndDiff = n - (1LL<<tfh) + 1;
    ll ndLeaves = (1LL << (th - 1));

    ll ans = 0;

    // cout << ndDiff << ' ' << ndLeaves << '\n';

    for(ll h=1;h<=th;h++)
    {
        ll bRank = h;

        if(bRank > k)continue;

        ll leaflen = (1LL<<(th - h));
        ll fNodes = ndDiff/leaflen;
        
        ll remNodes = ndDiff - fNodes*leaflen;
        
        ll eRankf = n - 2LL*leaflen + 2;
        ll eRankr = eRankf + leaflen - remNodes;
        ll eRanke = eRankf + leaflen;
        
        ll rNodes = (remNodes!=0LL);
        ll eNodes = (ndLeaves/leaflen) - fNodes - rNodes;

        // cout << h << ' ';
        // cout << fNodes << ' ' << rNodes << ' ' << eNodes << ' ';
        // cout << eRankf << ' ' << eRankr << ' ' << eRanke << '\n';

        if(eRankf >= k)
        {
            ans += fNodes;
        }

        if(eRankr >= k)
        {
            ans += rNodes;
        }

        if(eRanke >= k && h!=th)
        {
            ans += eNodes;
        }

        // cout << ans << '\n';
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