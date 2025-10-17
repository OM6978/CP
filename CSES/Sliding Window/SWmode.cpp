#include <bits/stdc++.h>
using namespace std;

using ll = long long;
struct Comp
{
    const vector<ll>& cost;

    Comp(const vector<ll>& c) : cost(c) {}

    bool operator()(int v1, int v2) const
    {
        if(cost[v1] != cost[v2])
            return cost[v1] < cost[v2];

        return v1 < v2;
    }
};

void solve()
{
    int N,K;
    cin>>N>>K;

    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }


    for(int i=0;i<K;i++)
    {

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
    
    solve();

    return 0;
}