#include <bits/stdc++.h>
using namespace std;

#define int long long

const int nullval = 0;
int getOp(int x,int y){return x+y;}

int getSTOp(vector<int> & st,int l,int r,int x,int lx,int rx)
{
    if(lx >= r || rx <= l)return nullval;
    if(lx >= l && rx <= r)return st[x];

    int mid = (lx+rx)>>1;
    int res1 = getSTOp(st,l,r,2*x+1,lx,mid);
    int res2 = getSTOp(st,l,r,2*x+2,mid,rx);
    return getOp(res1,res2);
}

int getSTWrapper(vector<int> & st,int l,int r)
{
    return getSTOp(st,l,r,0,0,(st.size()+1)/2);
}

void setSTVal(vector<int> & st,int l,int r,int x,int lx,int rx,int val)
{
    if(rx <= l || lx >= r)return;
    if(lx + 1 < rx)
    {
        int mid = (lx + rx)>>1;
        setSTVal(st,l,r,2*x+1,lx,mid,val);
        setSTVal(st,l,r,2*x+2,mid,rx,val);

        st[x] = getOp(st[2*x+1],st[2*x+2]);
    }
    else st[x] = val;
}

void setSTWrapper(vector<int> & st,int i,int val)
{
    setSTVal(st,i,i+1,0,0,(st.size()+1)/2,val);
}

vector<int> initST(vector<int> & ar)
{
    int N = ar.size();
    int sz = 1;
    while(sz<N)sz<<=1;

    vector<int> st(2*sz-1,nullval);
    for(int i=0;i<ar.size();i++)
        setSTWrapper(st,i,ar[i]);

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

        if(op == 1)setSTWrapper(ST,a1,a2);
        else cout << getSTWrapper(ST,a1,a2) << '\n';
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