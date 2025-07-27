#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N;
    cin>>N;

    vector<int> ar(N+1);
    for(int i=1;i<=N;i++)
    {
        cin>>ar[i];
    }

    sort(ar.begin(),ar.end());

    vector<int> pre(N+2,0);
    vector<int> suf(N+2,0);
    for(int i=1;i<=N;i++)
    {
        pre[i] += pre[i-1] + ar[i];
        suf[N-i+1] += suf[N-i+2] + ar[N-i+1];
    }

    int ops = 1e15;
    for(int i=1;i<=N;i++)
    {
        // cout << suf[i] << ' ';
        // cout << abs((i-1)*ar[i] - pre[i-1]) << ' ' << abs((N-i)*ar[i] - suf[i+1]) << '\n';
        ops = min(ops,abs((i-1)*ar[i] - pre[i-1]) + abs((N-i)*ar[i] - suf[i+1]));
    }

    cout << ops << '\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/CP/input.txt", "r", stdin);
        freopen("/home/om/Acads/CP/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    solve();

    return 0;
}