#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    vector<int> a(n),b(n),c(n),d(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    int ops = 0;
    for(int i=0;i<n;i++)
    {
        if(c[i] < a[i])
        {
            ops += a[i] - c[i];
        }
        if(d[i] < b[i])
        {
            ops += min(a[i],c[i]) + b[i] - d[i];
        }
    }

    cout << ops << '\n';
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