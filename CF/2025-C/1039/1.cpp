#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N,c;
    cin>>N>>c;

    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    sort(ar.begin(),ar.end(),greater<int>());

    int ans = 0,mult = 1;
    for(int i=0;i<N;i++)
    {
        if(ar[i]*mult <= c)
        {
            // cout << i << ' ';
            mult<<=1;
        }
        else ans++;
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
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}