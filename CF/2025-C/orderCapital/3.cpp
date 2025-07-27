#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;

    vector<pair<int,int>> ar(n);
    vector<pair<int,int>> xs,ys;
    vector<pair<int,int>> embeds(n);
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;

        ar[i].first = a;
        ar[i].second = b;

        xs.push_back({a,i});
        ys.push_back({b,i});
    }

    sort(xs.begin(),xs.end());
    sort(ys.begin(),ys.end());

    vector<int> ul,ur,ll,lr;
    for(int i=0;i<n;i++)
    {
        auto [a,in1] = xs[i];
        auto [b,in2] = ys[i];
        if(i < n/2)
        {
            embeds[in1].first = 0;
            embeds[in2].second = 0;
        }
        else
        {
            embeds[in1].first = 1;
            embeds[in2].second = 1;
        }
    }

    for(int i=0;i<n;i++)
    {
        auto [b1,b2] = embeds[i];
        if(b1 == 0 && b2 == 0)ll.push_back(i+1);
        else if(b1 == 0 && b2 == 1)ul.push_back(i+1);
        else if(b1 == 1 && b2 == 0)lr.push_back(i+1);
        else ur.push_back(i+1);
    }

    for(int i=0;i<ul.size();i++)
    {
        cout << ul[i] << ' ' << lr[i] << '\n';
    }
    for(int i=0;i<ur.size();i++)
    {
        cout << ur[i] << ' ' << ll[i] << '\n';
    }
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