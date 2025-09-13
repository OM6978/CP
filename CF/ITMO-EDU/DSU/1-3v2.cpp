#include <bits/stdc++.h>
using namespace std;

#define int long long

int get_a(int a,int* P)
{
    if(P[a] != a)return get_a(P[a],P);
    return a;
}

void union_s(int a,int b,int* P,int* rank,int* pts)
{
    int l1 = get_a(a,P);
    int l2 = get_a(b,P);

    if(l1 == l2)return;

    if(rank[l1] > rank[l2])swap(l1,l2);

    P[l1]=l2;
    pts[l1] -= pts[l2];
    rank[l2]+= (rank[l1]==rank[l2]);
}

int getpts(int a,int * P,int * pts)
{
    if(P[a] == a)return pts[a];
    return pts[a] + getpts(P[a],P,pts);
}

void solve()
{
    int N,M;
    cin>>N>>M;

    int P[N+1],rank[N+1],pts[N+1],coins[N+1];
    for(int i=0;i<N+1;i++)P[i] = i,rank[i] = 1,pts[i] = 0;

    for(int i=0;i<M;i++)
    {
        string s;
        cin>>s;

        if(s == "join")
        {
            int a,b;
            cin>>a>>b;

            union_s(a,b,P,rank,pts);

            int par = get_a(a,P);
        }
        else if(s == "add")
        {
            int x,v;
            cin>>x>>v;

            pts[get_a(x,P)] += v;
        }
        else
        {
            int x;
            cin>>x;

            cout << getpts(x,P,pts) << '\n';
        }
    }
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/Om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/Om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    solve();
    
    return 0;
}