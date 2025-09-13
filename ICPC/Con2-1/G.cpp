#include <bits/stdc++.h>
using namespace std;

#define int long long

int nCr(int n, int r) {
    if (r > n) return 0;
    r = min(r, n - r);
    if (r == 0) return 1;
    __int128 res = 1;
    for (int i = 1; i <= r; ++i) {
        res = res * (n - r + i) / i;
    }
    return (int)res;
}

int limSolve(int N,int K,vector<int> & ar,int in,int l,int r)
{
    if (K == 0) {
        return (l <= 0 && 0 <= r) ? 1 : 0;
    }

    if(in >= N)return 0;

    int ulin = in-1;
    for(int i=in;i<N;i++)
    {
        if(ar[i] < l)break;

        if(ar[i] <= r)
        {
            ulin = i;
            break;
        }
    }

    int llin = N;
    for(int i=in;i<N;i++)
    {
        if(ar[i] < l)
        {
            llin = i;
            break;
        }
    }

    int ans = 0;
    for(int i=ulin+1;i<llin;i++)
    {
        ans += nCr(N - i - 1,K - 1);
    }

    if(ulin >= in)ans += limSolve(N,K-1,ar,ulin+1,0,r - ar[ulin]);
    if(llin < N)ans += limSolve(N,K-1,ar,llin+1,l - ar[llin],r - ar[llin]);

    // cout << in << ' ';
    // cout << ulin << ' ' << llin << '\n';
    // cout << l << ' ' << r << ' ' << K << ' ' << ans << '\n';

    return ans;
}

void solve()
{
    int N,K;
    cin>>N>>K;

    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    sort(ar.begin(),ar.end(),greater<int>());

    int A,B;
    cin>>A>>B;

    int ans = limSolve(N,K,ar,1,A,B);
    if(ar[0] <= B && ar[0] >= A)
    {
        ans += limSolve(N,K-1,ar,1,0,B - ar[0]);
    }

    cout << ans << '\n';
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