#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define vv_int vector<vector<int>>

int good(int deletions,int* perms,string &t,string &p)
{
    int isdeleted[t.size()];
    for(int i=0;i<t.size();i++)isdeleted[i]=0;

    for(int i=0;i<deletions;i++)isdeleted[perms[i]-1]=1;

    int p_pnt = 0;
    for(int i=0;i<t.size();i++)
    {
        if(p[p_pnt]==t[i] && (isdeleted[i]==0))p_pnt++;
    }
    
    return (p_pnt>=p.size());
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/OneDrive/Acads/Contest-Codeforces/input.txt", "r", stdin);
        freopen("/home/om/OneDrive/Acads/Contest-Codeforces/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string t,p;
    cin>>t>>p;

    int N = t.size();
    int perms[N];

    for(int i=0;i<N;i++)
    {
        cin>>perms[i];
    }

    int l=0,r=N;
    while(l+1<r)
    {
        int mid = (l+r)/2;
        if(good(mid,perms,t,p))l=mid;
        else r=mid;
    }

    cout<<l<<endl;

    return 0;
}