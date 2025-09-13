#include <bits/stdc++.h>
using namespace std;

#define int long long

bool good(int num,int N,int K,int* a,int* b)
{
    int pos=0,bin = 0;
    for(int ain=N-1;ain>=0;ain--)
    {
        while(bin<N && num>=a[ain] + b[bin])
        {
            bin++;
        }

        pos+=bin;
    }

    return pos >= K;
}

void solve()
{
    int N,K;
    cin>>N>>K;

    int a[N],b[N];
    for(int i=0;i<N;i++)cin>>a[i];
    for(int i=0;i<N;i++)cin>>b[i];

    sort(a,a+N);
    sort(b,b+N);

    int l = 0,r = 2e9;
    while(l+1<r)
    {
        int mid = (l+r)/2;
        if(good(mid,N,K,a,b))r = mid;
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