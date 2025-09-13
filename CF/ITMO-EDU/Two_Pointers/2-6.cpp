#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N,K;
    cin>>N>>K;

    int ar[N];
    for(int i=0;i<N;i++)cin>>ar[i];

    int l=0,r=0,ans=0;
    int mini,maxi;

    multiset<int> m1;
    m1.insert(ar[0]);   

    while (r!=N)
    {
        mini = *m1.begin();
        maxi = *(--m1.end());

        if(maxi-mini > K)m1.erase(m1.find(ar[l++]));
        else
        {
            ans+= (r++ - l +1);
            if(r!=N)m1.insert(ar[r]);
        }
    }
    
    cout<<ans<<'\n';
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