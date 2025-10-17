#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    vector<int> xp;
    vector<int> yp;

    for(int i=0;i<N;i++)
    {
        int x,y;
        cin>>x>>y;

        xp.push_back(x);
        yp.push_back(y);
    }

    sort(xp.begin(),xp.end());
    sort(yp.begin(),yp.end());

    cout << xp[((N-1)/2)] << ' ' << yp[((N-1)/2)] << '\n';
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