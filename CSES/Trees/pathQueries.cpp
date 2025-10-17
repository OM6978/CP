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
    for(int i=0;i<N;i++)
        setSTWrapper(st,i,ar[i]);

    return st;
}

void dfs(int u,int par,vector<vector<int>> & tree,vector<int> & pstSum,int & timer,vector<int> & in,vector<int> & out)
{
    in[u] = timer;

    timer++;

    for(int v : tree[u])
    {
        if(v == par)continue;

        pstSum[v] += pstSum[u];

        dfs(v,u,tree,pstSum,timer,in,out);
    }

    out[u] = timer;
}

void solve()
{
    int N,Q;
    cin>>N>>Q;

    vector<int> vals(N+1);
    for(int u=1;u<=N;u++)
    {
        cin>>vals[u];
    }

    vector<vector<int>> tree(N+1);
    
    for(int i=0;i<N-1;i++)
    {
        int u,v;
        cin>>u>>v;
    
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> pstSum(vals.begin(),vals.end());
    vector<int> in(N+1);
    vector<int> out(N+1);

    int timer = 0;
    dfs(1,0,tree,pstSum,timer,in,out);

    vector<int> sChanges(N+1,0);
    auto sti = initST(sChanges);

    while(Q--)
    {
        int qt;
        cin>>qt;

        if(qt == 1)
        {
            int s,x;
            cin>>s>>x;

            int tin = in[s];
            int tout = out[s];

            int dv = x - vals[s];

            vals[s] = x;

            setSTWrapper(sti,tin,getSTWrapper(sti,tin,tin+1) + dv);
            setSTWrapper(sti,tout,getSTWrapper(sti,tout,tout+1) - dv);
        }
        else
        {
            int s;
            cin>>s;

            int tin = in[s];
            
            cout << getSTWrapper(sti,0,tin+1) + pstSum[s] << '\n';
        }
    }
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