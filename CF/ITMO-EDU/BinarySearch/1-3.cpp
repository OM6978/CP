#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define int long long

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N,K;
    cin>>N>>K;
    int startarr[N];
    for(int i=0;i<N;i++)cin>>startarr[i];

    vector<int> inp(startarr,startarr+N);

    int temp;
    while(K--)
    {
        cin>>temp;
        auto ans = lower_bound(inp.begin(),inp.end(),temp);
        auto lol = (ans - inp.begin());
        cout<< lol + 1<<endl;
    }
    return 0;
}