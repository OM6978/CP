#include <bits/stdc++.h>
using namespace std;

#define int long long

int findSum(int dpernum,int r)
{
    int res = 0;
    int div = 10;
    int dten = 1;

    for(int i=0;i<dpernum;i++)
    {
        int dnum = r/div;
        res += (dnum*45LL)*dten;

        int rem = r%div;
        int rnum = rem/dten;

        int rsum = ((rnum*(rnum-1LL))/2LL)*dten;
        res += rsum;
        
        int drem = rem%dten;
        res += (drem+1)*rnum;

        div*=10LL;
        dten*=10LL;
    }

    return res;
}

void solve()
{
    int K;
    cin>>K;

    int r = 0;
    int dpernum = 1;
    int mult = 1;

    while(K - dpernum*mult*9LL >= 0)
    {
        K -= dpernum*mult*9LL;
        r += mult*9LL;

        dpernum++;
        mult*=10LL;
    }

    r += K/dpernum;
    K %= dpernum;

    int fulldsum = findSum(dpernum,r);

    r++;
    vector<int> rdigits;
    while(r)
    {
        rdigits.push_back(r%10);
        r/=10;
    }

    reverse(rdigits.begin(),rdigits.end());

    int ans = fulldsum;
    for(int i=0;i<K;i++)
    {
        ans += rdigits[i];
    }

    cout << ans << '\n';
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