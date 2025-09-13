#include <bits/stdc++.h>
using namespace std;

bool good(double ans,vector<pair<int,int>> & inp,int N,int K)
{
    double ar[N];
    for(int i=0;i<N;i++)
    {
        pair<double,double> p = inp[i];
        ar[i] = p.first - ans*p.second;
    }

    sort(ar,ar+N,greater<double>());

    double ret = 0;
    for(int i=0;i<K;i++)
    {
        ret+= ar[i];
    }

    return ret <= 0;
}

void solve()
{
    int N,K;
    cin>>N>>K;

    vector<pair<int,int>> inp;

    for(int i=0;i<N;i++)
    {
        pair<int,int> temp;
        cin>>temp.first>>temp.second;

        inp.push_back(temp);
    }

    double l = 0,r = 1e5;
    while(l+1e-6<=r)
    {
        double mid = (l+r)/2;
        if(good(mid,inp,N,K))r = mid;
        else l = mid;
    }

    cout << setprecision(10) << r << '\n';
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