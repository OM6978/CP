#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    string burger;
    cin>>burger;

    int n1,n2,n3;
    cin>>n1>>n2>>n3;

    int p1,p2,p3;
    cin>>p1>>p2>>p3;

    int roubles;
    cin>>roubles;

    int q1=0,q2=0,q3=0;
    for(char a:burger)
    {
        q1 += (a=='B');
        q2 += (a=='S');
        q3 += (a=='C');
    }

    auto good = [&](int num)->bool
    {
        int needed=0;
        needed += max(q1*num - n1,0LL)*p1;
        needed += max(q2*num - n2,0LL)*p2; 
        needed += max(q3*num - n3,0LL)*p3;

        return (needed <= roubles);
    };

    int l = 0LL,r=(1LL<<50);
    while(l+1<r)
    {
        int mid = ((l+r)>>1);
        if(good(mid))l = mid;
        else r = mid;
    }

    cout<<l<<'\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}