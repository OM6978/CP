#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N,K;
    cin>>N>>K;

    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    vector<int> vouchers(K);
    for(int i=0;i<K;i++)
    {
        cin>>vouchers[i];
    }

    sort(ar.begin(),ar.end(),greater<int>());
    sort(vouchers.begin(),vouchers.end());

    int p = 0;
    int cost = 0;
    for(int i=0;i<K;i++)
    {
        int voucher = vouchers[i];

        for(int j=0;j<min(voucher-1,N-p);j++)
        {
            cost += ar[p+j];
        }

        p += voucher;
    }

    for(int i=p;i<N;i++)
    {
        cost += ar[i];
    }

    cout << cost << '\n';
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