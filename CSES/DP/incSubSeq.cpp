#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    multiset<int> ms;
    for(int i=1;i<=N;i++)
    {
        int a;
        cin>>a;

        auto it = ms.lower_bound(a);
        if(it != ms.end())
            ms.erase(it);
            
        ms.insert(a);
    }

    cout << ms.size() << '\n';
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