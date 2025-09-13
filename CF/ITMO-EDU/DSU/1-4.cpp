#include <bits/stdc++.h>
using namespace std;

int get_a(int a,int* P)
{
    if(P[a] != a)P[a] = get_a(P[a],P);
    return P[a];
}

void union_s(int a,int b,int* P,int* rank)
{
    int l1 = get_a(a,P);
    int l2 = get_a(b,P);

    if(l1 == l2)return;

    if(rank[l1] > rank[l2])l2 = l1 + l2 - (l1=l2);

    P[l1]=l2;
    rank[l2]+= (rank[l1]==rank[l2]);
}

void solve()
{
    int N,M,K;
    cin>>N>>M>>K;

    string s;
    int u,v;
    while(M--)cin>>u>>v;

    vector<tuple<string,int,int>> cmds;
    for(int i=0;i<K;i++)
    {
        cin>>s>>u>>v;
        cmds.push_back({s,u,v});
    }

    int P[N+1],R[N+1];
    for(int i=1;i<=N;i++)P[i] = i,R[i] = 1;

    vector<string> ans;
    for(int i=K-1;i>=0;i--)
    {
        auto & [ss,uu,vv] = cmds[i];
        if(ss == "cut")union_s(uu,vv,P,R);
        else ans.push_back((get_a(uu,P) == get_a(vv,P))?"YES\n":"NO\n");
    }
    
    reverse(ans.begin(),ans.end());
    for(auto & ss : ans)cout << ss;
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