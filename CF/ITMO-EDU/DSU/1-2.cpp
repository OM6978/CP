#include <bits/stdc++.h>
using namespace std;

int get_a(int a,int* P)
{
    if(P[a] != a)P[a] = get_a(P[a],P);
    return P[a];
}

void union_s(int a,int b,int* P,int* rank,int* max_e,int* min_e,int* siz_e)
{
    int l1 = get_a(a,P);
    int l2 = get_a(b,P);

    if(l1 == l2)
    {
        // cout<<"lol"<<'\n';
        return;
    }

    if(rank[l1] > rank[l2])l2 = l1 + l2 - (l1=l2);

    P[l1]=l2;
    rank[l2]+= (rank[l1]==rank[l2]);

    max_e[l2] = max(max_e[l1],max_e[l2]);
    min_e[l2] = min(min_e[l1],min_e[l2]);
    siz_e[l2] = siz_e[l1] + siz_e[l2];
}

void solve()
{
    int N,M;
    cin>>N>>M;

    int P[N+1],rank[N+1],max_e[N+1],min_e[N+1],siz_e[N+1];
    for(int i=1;i<=N;i++)P[i] = i,rank[i]=1,max_e[i]=i,min_e[i]=i,siz_e[i]=1;

    for(int i=0;i<M;i++)
    {
        string s;
        cin>>s;

        if(s == "union")
        {
            int a,b;
            cin>>a>>b;
            union_s(a,b,P,rank,max_e,min_e,siz_e);
        }
        else
        {
            int a;
            cin>>a;

            cout << min_e[get_a(a,P)] << ' ' << max_e[get_a(a,P)] << ' ' << siz_e[get_a(a,P)] << '\n';
        }
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