#include <bits/stdc++.h>
using namespace std;

#define int long long

int contri(int diff,int num,int div,int l,int mult)
{
    int nums = diff/div;
    int adds = 0;
    int rem = diff%div;
    for(int i=0;i<rem;i++)
    {
        int val = i+nums*div+l;
        if(!(val%num!=0 || (2<num && val%2 ==0) || (3 < num && val%3==0) || (5 < num && val%5==0)))
        {
            adds++;
        }
    }

    return adds+nums*mult;
}

void solve()
{
    int l,r;
    cin>>l>>r;

    int diff = r - l + 1;

    int twos = contri(diff,2,2,l,1);
    int threes = contri(diff,3,6,l,1);
    int fives = contri(diff,5,30,l,2);
    int sevens = contri(diff,7,210,l,8);

    cout << diff - twos - threes - fives - sevens << '\n';
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