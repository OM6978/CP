#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define int long long

int w,h,n;

int doesitfit(int x)
{
    int a= x/w,b=x/h;
    if(a*b>=n)return 1;
    else return 0;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>w>>h>>n;
    int l=0,r=1;
    while(!doesitfit(r))r*=2;

    while(l+1!=r)
    {
        int m=(l+r)/2;
        if(doesitfit(m))r=m;
        else l=m;
    }

    cout<<r<<endl;
    return 0;
}