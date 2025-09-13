#include <bits/stdc++.h>
using namespace std;

#define int long long

pair<int,int> getop(pair<int,int> & x,pair<int,int> & y)
{
    if(x.first == y.first)return {x.first,x.second + y.second};
    else if(x.first < y.first)return x;
    else return y;
}
pair<int,int> nullval(){return {1e17,1};}

pair<int,int> getSTop(vector<pair<int,int>> & st,int l,int r,int x,int lx,int rx)
{
    if(lx >= r || rx <= l)return nullval();
    if(lx >= l && rx <= r)return st[x];

    int mid = (lx+rx)>>1;
    auto res1 = getSTop(st,l,r,2*x+1,lx,mid);
    auto res2 = getSTop(st,l,r,2*x+2,mid,rx);
    return getop(res1,res2);
}

pair<int,int> getSTwrapper(vector<pair<int,int>> & st,int l,int r)
{
    return getSTop(st,l,r,0,0,(st.size()+1)/2);
}

void setSTval(vector<pair<int,int>> & st,int l,int r,int x,int lx,int rx,int val)
{
    if(rx <= l || lx >= r)return;
    if(lx + 1 < rx)
    {
        int mid = (lx + rx)>>1;
        setSTval(st,l,r,2*x+1,lx,mid,val);
        setSTval(st,l,r,2*x+2,mid,rx,val);

        st[x] = getop(st[2*x+1],st[2*x+2]);
    }
    else st[x] = {val,1};
}

void setSTwrapper(vector<pair<int,int>> & st,int i,int val)
{
    setSTval(st,i,i+1,0,0,(st.size()+1)/2,val);
}

vector<pair<int,int>> initST(vector<int> & ar)
{
    int N = ar.size();
    int sz = 1;
    while(sz<N)sz<<=1;

    vector<pair<int,int>> st(2*sz-1,nullval());
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
        else
        {
            auto [num,val] = getSTwrapper(ST,a1,a2);
            cout << num << ' ' << val << '\n';
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