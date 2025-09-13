#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

int good(double x,double C)
{
    return (x*x + sqrt(x) > C);
}

signed main()
{
    double C;
    cin>>C;

    double l = 0,r=1e5;

    while(r-l>1e-6)
    {
        double m = (l+r)/2;
        if(good(m,C))r=m;
        else l=m;
    }

    cout<<setprecision(20)<<r<<endl;

    return 0;
}