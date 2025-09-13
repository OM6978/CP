#include <bits/stdc++.h>
using namespace std;

#define int long long

int getop(int x,int y){return min(x,y);}
int nullval(){return 1e17;}

int getSTop(vector<int> & st,int l,int r,int x,int lx,int rx)
{
    if(lx >= r || rx <= l)return nullval();
    if(lx >= l && rx <= r)return st[x];

    int mid = (lx+rx)>>1;
    int res1 = getSTop(st,l,r,2*x+1,lx,mid);
    int res2 = getSTop(st,l,r,2*x+2,mid,rx);
    return getop(res1,res2);
}

int getSTwrapper(vector<int> & st,int l,int r)
{
    return getSTop(st,l,r,0,0,(st.size()+1)/2);
}

void setSTval(vector<int> & st,int l,int r,int x,int lx,int rx,int val)
{
    if(rx <= l || lx >= r)return;
    if(lx + 1 < rx)
    {
        int mid = (lx + rx)>>1;
        setSTval(st,l,r,2*x+1,lx,mid,val);
        setSTval(st,l,r,2*x+2,mid,rx,val);

        st[x] = getop(st[2*x+1],st[2*x+2]);
    }
    else st[x] = val;
}

void setSTwrapper(vector<int> & st,int i,int val)
{
    setSTval(st,i,i+1,0,0,(st.size()+1)/2,val);
}

vector<int> initST(vector<int> & ar)
{
    int N = ar.size();
    int sz = 1;
    while(sz<N)sz<<=1;

    vector<int> st(2*sz-1,nullval());
    for(int i=0;i<ar.size();i++)
        setSTwrapper(st,i,ar[i]);

    return st;
}

void solve()
{
    int N,M;
    cin>>N>>M;

    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    auto ST = initST(ar);

    while(M--)
    {
        int op,a1,a2;
        cin>>op>>a1>>a2;

        if(op == 1)setSTwrapper(ST,a1,a2);
        else cout << getSTwrapper(ST,a1,a2) << '\n';
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