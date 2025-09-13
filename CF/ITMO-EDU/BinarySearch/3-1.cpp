#include <bits/stdc++.h>
using namespace std;

double get_left(pair<int,int> & ent,double time)
{
    return ent.first - ent.second*time;
}

double get_right(pair<int,int> & ent,double time)
{
    return ent.first + ent.second*time;
}

bool good(double time,int N,pair<int,int> * ar)
{
    double l = get_left(ar[0],time),r = get_right(ar[0],time);

    for(int i=1;i<N;i++)
    {
        double ll = get_left(ar[i],time),rr = get_right(ar[i],time);
        l = max(ll,l),r = min(rr,r);

        if(l>r)return false;
    }

    return true;
}

void solve()
{
    int N;
    cin>>N;

    pair<int,int> ar[N];
    for(int i=0;i<N;i++)
    {
        cin>>ar[i].first>>ar[i].second;
    }

    double l=0,r=1e15;
    while(l+1e-6<=r)
    {
        double mid = (l+r)/2;
        if(good(mid,N,ar))r = mid;
        else l = mid;
    }

    cout << setprecision(20) << r << '\n';
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