#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve()
{
    int N,K;
    cin>>N>>K;

    ll x,a,b,c;
    cin>>x>>a>>b>>c;

    queue<ll> q;
    q.push(x);

    ll curr = x;
    ll bxor = x;
    ll ans = 0;

    while(q.size() < K)
    {
        ll next = (curr*a + b)%c;
        bxor ^= next;

        q.push(next);
        curr = next;
    }

    ans ^= bxor;

    for(int i=K;i<N;i++)
    {
        ll next = (curr*a + b)%c;
        bxor ^= next;

        ll prev = q.front();
        q.pop();

        bxor ^= prev;

        ans ^= bxor;

        q.push(next);
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