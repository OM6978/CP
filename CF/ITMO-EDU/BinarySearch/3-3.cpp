#include <bits/stdc++.h>
using namespace std;

#define int long long

bool good(int dist,int * ar,int N,int K)
{
    int last = ar[0];

    for(int i=1;i<N;i++)
    {
        if(ar[i] - last - 1 >= dist)
        {
            last = ar[i];
            if((--K) == 1)return true;
        }
    }

    return false;
}

void solve()
{
    int N,K;
    cin>>N>>K;

    int ar[N];
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    int l=0,r=1e9;
    while(l+1<r)
    {
        int mid = (l+r)>>1;
        if(!good(mid,ar,N,K))r = mid;
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