#include <bits/stdc++.h>
using namespace std;

#define int long long

int MOD = 1e9 + 7;

const int nullval = 0;
int getOp(int x,int y){return (x+y)%MOD;}

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
    for(int i=0;i<N;i++)
        setSTWrapper(st,i,ar[i]);

    return st;
}

void solve()
{
    int N;
    cin>>N;

    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    auto sar = ar;
    sort(sar.begin(),sar.end());

    vector<int> svals(N,0LL);
    auto st = initST(svals);

    for(int i=0;i<N;i++)
    {
        int in = lower_bound(sar.begin(),sar.end(),ar[i]) - sar.begin();
        int appendSubs = getSTWrapper(st,0,in);
        
        svals[in] = (svals[in] + appendSubs + 1)%MOD;
        setSTWrapper(st,in,svals[in]);
    }

    cout << getSTWrapper(st,0,N) << '\n';
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