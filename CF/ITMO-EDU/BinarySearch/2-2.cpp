#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define double long double

int n,k;
int isdistrib(double *ropes,double x)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=floor(ropes[i]/x);
    }
    if(sum>=k)return 1;
    else return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>k;
    double ropes[n];
    for(int i=0;i<n;i++)cin>>ropes[i];

    double l=0,r=*max_element(ropes,ropes+n)+1;

    while(r-l>1e-6)
    {
        double m=(l+r)/2;
        if(isdistrib(&ropes[0],m))l=m;
        else r=m;
    }
    cout<<setprecision(20)<<l<<endl;
    return 0;
}