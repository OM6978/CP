#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll getOp(ll a,ll b)
{
    return (a | b);
}

struct twoStackOp
{
    stack<ll> eStk,opStk;
    ll eOp;
    int K;

    twoStackOp(int k)
    {
        K = k;
        eOp = 0;
    }

    void push(ll x)
    {
        if(eStk.size() == K)
        {
            opStk.push(eStk.top());
            eStk.pop();

            while(eStk.size())
            {
                opStk.push(getOp(eStk.top(),opStk.top()));
                eStk.pop();
            }

            eOp = 0;
        }
        
        if(opStk.size())opStk.pop();

        eOp = getOp(eOp,x);
        eStk.push(x);
    }

    ll swOp()
    {
        if(opStk.size())
        {
            return getOp(opStk.top(),eOp);
        }
        return eOp;
    }
};

void solve()
{
    int N,K;
    cin>>N>>K;

    ll x,a,b,c;
    cin>>x>>a>>b>>c;

    ll curr = x;
    ll ans = 0;
    
    auto twinStk = twoStackOp(K);
    twinStk.push(x);

    for(int i=1;i<K;i++)
    {
        ll next = (curr*a + b)%c;
        twinStk.push(next);

        curr = next;
    }

    ans ^= twinStk.swOp();

    for(int i=K;i<N;i++)
    {
        ll next = (curr*a + b)%c;
        twinStk.push(next);

        ans ^= twinStk.swOp();

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