#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve()
{
    int N,K;
    cin>>N>>K;

    ll x,a,b,c;
    cin>>x>>a>>b>>c;

    deque<pair<ll,int>> dq;
    dq.push_back({x,0});

    ll curr = x;
    ll ans = 0;

    for(int i=1;i<K;i++)
    {
        ll next = (curr*a + b)%c;

        while(dq.size() > 0 && dq.back().first >= next)
        {
            dq.pop_back();
        }

        dq.push_back({next,i});
        curr = next;
    }

    ans ^= (ll)dq.front().first;

    for(int i=K;i<N;i++)
    {
        ll next = (curr*a + b)%c;

        auto [prev,ind] = dq.front();
        
        if(ind == i-K)
        {
            dq.pop_front();
        }

        while(dq.size() > 0 && dq.back().first >= next)
        {
            dq.pop_back();
        }

        dq.push_back({next,i});

        ans ^= dq.front().first;

        curr = next;
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