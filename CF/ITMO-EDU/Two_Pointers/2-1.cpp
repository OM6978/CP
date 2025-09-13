#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N,S;
    cin>>N>>S;

    int ar[N];
    for(int i=0;i<N;i++)cin>>ar[i];

    int l=0,r=-1,sum = 0,most = 0;
    while(r!=N-1)
    {
        while(sum <= S)
        {
            most = max(most,r - l + 1);
            if(r >= N-1)break;
            sum+= ar[++r];
        }

        while(sum > S)sum-= ar[l++];
    }

    cout<< most <<'\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/OneDrive/Contest-Codeforces/input.txt", "r", stdin);
        freopen("/home/om/OneDrive/Contest-Codeforces/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}