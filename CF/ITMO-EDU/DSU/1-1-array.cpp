#include <bits/stdc++.h>
using namespace std;

#define ump unordered_map

void union_s(int a,int b,int* P,ump <int,vector<int>> & mp)
{
    if(P[a]==P[b])return;

    if(mp[P[a]].size() > mp[P[b]].size())
        a = b + a - (b=a);

    vector<int> & v1 = mp[P[b]];
    vector<int> & v2 = mp[P[a]];

    for(int x : v2)P[x] = P[b];

    v1.insert(v1.end(),v2.begin(),v2.end());
    v2.clear();
}

void solve()
{
    int N,M;
    cin>>N>>M;

    int P[N+1];
    for(int i=1;i<=N;i++)P[i] = i;

    ump <int,vector<int>> mp;
    for(int i=1;i<=N;i++)mp[i].push_back(i);

    for(int i=0;i<M;i++)
    {
        string s;
        cin>>s;

        int a,b;
        cin>>a>>b;

        if(s == "union")union_s(a,b,P,mp);
        else cout << ((P[a] == P[b])?"YES":"NO") << '\n';
    }
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