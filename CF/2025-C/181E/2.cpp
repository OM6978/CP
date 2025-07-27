#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int a,b,k;
    cin>>a>>b>>k;

    int g = __gcd(a,b);
    int d = max(a/g,b/g);
    if(a == 0 && b==0)cout << 0 << '\n';
    else if(d > k)cout << 2 << '\n';
    else cout << 1 << '\n';
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