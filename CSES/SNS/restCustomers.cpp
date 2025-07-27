#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    int ans = 0;

    multiset<pair<int,int>> msp;
    for(int i=0;i<N;i++)
    {
        int a,b;
        cin>>a>>b;

        msp.insert({a,0});
        msp.insert({b,1});
    }

    int c=0;
    for(auto [t,type] : msp)
    {
        if(type)
        {
            c--;
        }
        else
        {
            c++;
        }

        ans = max(ans,c);
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