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

void poDfs(int u,int par,vector<vector<int>> & tree,vector<int> & stSum,vector<int> & stsz,vector<int> & vals,vector<int> & preOrder,unordered_map<int,int> & preOrderHash)
{
    preOrderHash[u] = preOrder.size();
    preOrder.push_back(u);

    stSum[u] += vals[u];
    stsz[u] = 1;

    for(int v : tree[u])
    {
        if(v == par)continue;

        poDfs(v,u,tree,stSum,stsz,vals,preOrder,preOrderHash);

        stSum[u] += stSum[v];
        stsz[u] += stsz[v];
    }
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

    vector<int> stSum(N+1,0);
    vector<int> stsz(N+1,0);
    vector<int> preOrder;

    unordered_map<int,int> preOrderHash;

    poDfs(1,0,tree,stSum,stsz,vals,preOrder,preOrderHash);

    vector<int> sChanges(N,0);
    auto segTreei = initST(sChanges);

    // for(int i=0;i<N;i++)
    // {
    //     cout << preOrder[i] << ' ';
    // }
    // cout << "\n";

    while(Q--)
    {
        int qt;
        cin>>qt;

        if(qt == 1)
        {
            int s,x;
            cin>>s>>x;

            int poInd = preOrderHash[s];
            int d = x - vals[s];

            vals[s] = x;
            setSTWrapper(segTreei,poInd,getSTWrapper(segTreei,poInd,poInd+1) + d);
        }
        else
        {
            int s;
            cin>>s;

            int poInd = preOrderHash[s];

            cout << getSTWrapper(segTreei,poInd,poInd+stsz[s]) + stSum[s] << '\n';
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