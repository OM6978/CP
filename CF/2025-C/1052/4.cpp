#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> lrSolve(int l,int r)
{
    if(l == r)return {r};
    if(l == r - 1)
    {
        return {r,l};
    }
    
    int hbv = 1LL;
    while((hbv<<1) <= r)
    {
        hbv <<= 1;
    }

    unordered_map<int,int> res;
    bool flag = false;

    int cr = hbv;
    int cl = hbv - 1;
    for(cl = hbv - 1;cl>=l;cl--)
    {
        if(cr > r)
        {
            flag = true;
            break;
        }

        res[cl] = cr;
        res[cr] = cl;
        cr++;
    }

    // cout << cl << ' ' << cr << ' ';
    // cout << l << ' ' << r << ' ' << flag << '\n';

    if(cl+1 != l || cr-1 != r)
    {
        if(flag)
        {
            auto sl = lrSolve(l,cl);
            for(int i=0;i<sl.size();i++)
            {
                res[i+l] = sl[i];
            }
        }
        else
        {
            auto sr = lrSolve(cr - hbv,r - hbv);
            for(int i=0;i<sr.size();i++)
            {
                res[i+hbv+cr] = sr[i] + hbv;
            }
        }
    }

    vector<int> vres;
    for(int e=l;e<=r;e++)
    {
        vres.push_back(res[e]);
    }

    return vres;
}

void solve()
{
    int l,r;
    cin>>l>>r;

    auto res = lrSolve(l,r);

    int ans = 0;
    for(int i=0;i<(int)res.size();i++)
    {
        int a = res[i];
        int b = l + i;

        ans += (a | b);
    }

    cout << ans << '\n';
    for(int a : res)
    {
        cout << a << ' ';
    }
    cout << '\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/CP/input.txt", "r", stdin);
        freopen("/home/om/Acads/CP/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}