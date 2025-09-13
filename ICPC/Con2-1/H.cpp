#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    int most = 100;
    int curr = 100;

    for(int i=0;i<N;i++)
    {
        int box;
        cin>>box;

        curr+=box;
        most = max(most,curr);
    }

    cout << most << '\n';
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