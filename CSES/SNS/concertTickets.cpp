#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N,M;
    cin>>N>>M;

    multiset<int> ms;
    for(int i=0;i<N;i++)
    {
        int a;
        cin>>a;
        ms.insert(a);
    }

    for(int i=0;i<M;i++)
    {
        int a;
        cin>>a;

        auto it = ms.upper_bound(a);
        if(it==ms.begin())
        {
            cout << -1 << '\n';
        }
        else
        {
            it--;
            cout << *it << '\n';
            ms.erase(it);
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
    
    solve();

    return 0;
}