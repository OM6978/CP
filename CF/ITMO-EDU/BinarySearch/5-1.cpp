#include <bits/stdc++.h>
using namespace std;

#define int long long

bool good(int num,int* ls,int* rs,int N,int K)
{
    int pos = 0;
    for(int i=0;i<N;i++)
    {
        int l = ls[i],r = rs[i];
        if(num >=l)pos += min(num-l+1,r-l+1);
    }

    return pos > K;
}

void solve()
{
    int N,K;
    cin>>N>>K;

    int ls[N],rs[N];
    for(int i=0;i<N;i++)
    {
        cin>>ls[i]>>rs[i];
    }

    int l = -2e9-1,r = 2e9;
    while(l+1<r)
    {
        int mid = (l+r)/2;
        if(good(mid,ls,rs,N,K))r = mid;
        else l = mid;
    }

    cout << r << '\n';
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