#include <bits/stdc++.h>
using namespace std;

int in1,in2;
bool good(double avg,int * ar,int N,int D)
{
    double pref[N+1];
    pref[0] = 0;

    for(int i=1;i<=N;i++)
    {
        pref[i]= pref[i-1] + (ar[i-1] - avg);
    }

    double most[N+1];
    most[N] = pref[N];
    for(int i=N-1;i>=0;i--)
    {
        most[i] = max(most[i+1],pref[i]);
    }

    for(int i=0;i<=N-D;i++)
    {
        if(most[i+D] >= pref[i])
        {
            for(int j=i+D;j<=N;j++)
            {
                if(pref[j] >= pref[i])
                {
                    in2 = j;
                    break;
                }
            }
            in1 = i+1;
            return true;
        }
    }

    return false;
}

void solve()
{
    int N,D;
    cin>>N>>D;

    int ar[N],p[N],most[N];
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    double l = 0,r = 101;
    while(l+1e-5<=r)    
    {
        double mid = (l+r)/2;
        if(good(mid,ar,N,D))l=mid;
        else r=mid;
    }

    good(l,ar,N,D);

    cout << in1 << ' ' << in2 << '\n';
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