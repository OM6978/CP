#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N,S;
    cin>>N>>S;

    int ar[N];
    for(int i=0;i<N;i++)cin>>ar[i];

    int totsum = 0;
    for(int i=0;i<N;i++)totsum+=ar[i];

    int l=0,sum=0,least = 3e18+1;
    int r = -1,ind = -1;

    int mult = S/totsum;
    r+=N*mult;
    sum+=totsum*mult;

    while(l<N)
    {
        while(sum<S)sum+=ar[(++r)%N];

        if(least > r-l+1)
        {
            least = r-l+1;
            ind = l+1;
        }

        sum-=ar[l++];
    }

    cout << ind << ' ' << least << '\n';
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