#include <bits/stdc++.h>
using namespace std;

#define int long long

bool good(int num,int N,int K)
{
    int pos = 0,last = 1;
    for(int i=N;i>=1;i--)
    {
        while(last <= N && i*last <= num)
        {
            last++;
        }

        pos+=last-1;
    }

    return pos >= K;
}

void solve()
{
    int N,K;
    cin>>N>>K;

    int l = 0,r = 1e10;
    while(l+1<r)
    {
        int mid = (l+r)/2;
        if(good(mid,N,K))r = mid;
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