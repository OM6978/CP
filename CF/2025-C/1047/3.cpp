#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int a,b;
    cin>>a>>b;

    if(b%2 == 0)
    {
        int d = b/2LL;
        a *= d;
        b /= d;
    }
    else
    {
        a *= b;
        b = 1;
    }

    cout << (((a + b)&1)?-1:a+b)<< '\n';
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