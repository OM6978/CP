#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n,x,y;
    cin>>n>>x>>y;

    int ans=min(x,y);
    n=n-1;
    if(n==0){cout<<ans<<endl;return 0;}

    int num1 = lcm(x,y),num2 = num1/min(x,y) + num1/max(x,y);
    int temp = n/num2;
    ans += temp*num1;

    if(n%num2!=0)
    {
        int temp2=(n-(temp*num2))*min(x,y),temp3 =0;
        // cout<<temp2<<endl;
        while(temp2>temp3)
        {
            temp2-=min(x,y);
            temp3+=max(x,y);
        }

        int temp4=max(temp2,temp3),temp5 = max(temp2+min(x,y),temp3-max(x,y));
        ans+=min(temp4,temp5);
    }

    cout<<ans<<endl;
    return 0;
}