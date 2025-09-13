#include <bits/stdc++.h>
using namespace std;

#define int long long

struct m_stack
{
    stack<int> pref,nums;

    void push(int x)
    {
        nums.push(x);

        if(pref.size())pref.push(__gcd(pref.top(),x));
        else pref.push(x);
    }

    void pop()
    {
        pref.pop();
        nums.pop();
    }

    int top()
    {
        if(pref.size())return pref.top();
        else return 0;
    }

    int size(){return pref.size();}
};

m_stack s1,s2;

void rrremove()
{
    if(s2.size()==0)
    {
        while(s1.size())
        {
            s2.push(s1.nums.top());
            s1.pop();
        }
    }
    s2.pop();
}

void solve()
{
    int N;
    cin>>N;

    int ar[N];
    for(int i=0;i<N;i++)cin>>ar[i];

    int ans = 1e9;
    int l=0,r=0;
    while(r<=N)
    {
        if(__gcd(s1.top(),s2.top())==1)
        {
            ans = min(ans,r-l);
            rrremove();
            l++;
        }
        else if(r++!=N)s1.push(ar[r-1]);
    }

    cout << ((ans==1e9)?-1:ans) << '\n';
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