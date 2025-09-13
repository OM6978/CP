#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int get_a(int a,int* P)
{
    if(P[a] != a)return get_a(P[a],P);
    return P[a];
}

ll get_exp(int a,int* P,ll* exp)
{
    ll ret = exp[a];
    if(P[a]!=a)ret += get_exp(P[a],P,exp);
    return ret;
}

void union_s(int a,int b,int* P,int* rank,ll* exp)
{
    int l1 = get_a(a,P);
    int l2 = get_a(b,P);

    if(l1 == l2)return;

    if(rank[l1] > rank[l2])swap(l1,l2);

    P[l1]=l2;
    exp[l1] -= exp[l2];
    rank[l2] += (rank[l1]==rank[l2]);
}

void add_s(int a,int b,int* P,ll* exp)
{
    int p = get_a(a,P);
    exp[p] += b;
}

void solve()
{
    int N,M;
    cin>>N>>M;

    int rank[N+1],P[N+1];
    ll exp[N+1];
    for(int i=1;i<=N;i++)rank[i]=1,P[i]=i,exp[i] = 0;

    for(int i=0;i<M;i++)
    {
        string s;
        cin>>s;

        int a,b;
        cin>>a;
        if(s!="get")cin>>b;

        if(s == "join")union_s(a,b,P,rank,exp);
        else if(s == "add")add_s(a,b,P,exp);
        else cout << get_exp(a,P,exp) << '\n';
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