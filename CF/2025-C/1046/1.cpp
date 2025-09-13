#include <bits/stdc++.h>
using namespace std;

bool compf(int a,int b)
{
    return 2*a + 2 < b;
}

void solve()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    if(a <= b)
    {
        if(compf(a,b))
        {
            cout << "NO\n";
            return;
        }
    }
    else
    {
        if(compf(b,a))
        {
            cout << "NO\n";
            return;
        }
    }

    int cdel = c - a;
    int ddel = d - b;

    if(cdel <= ddel)
    {
        if(compf(cdel,ddel))
        {
            cout << "NO\n";
            return;
        }
    }
    else
    {
        if(compf(ddel,cdel))
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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