#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
void solve()
{
    int N,x;
    cin>>N>>x;
 
    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }
 
    sort(ar.begin(),ar.end());
 
    int ans = 0;
 
    int l = 0,r = N-1;
    while(l < r)
    {
        int a = ar[l],b = ar[r];
        if(a + b <= x)
        {
            l++;
        }
 
        ans++;
        r--;
    }
 
    if(l==r)ans++;
 
    cout << ans << '\n';
}
 
signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif
 
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    solve();
 
    return 0;
}