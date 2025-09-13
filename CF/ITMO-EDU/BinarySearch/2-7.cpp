#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define vv_int vector<vector<int>>
#define int long long

int good(int N,int* groups,int K,int val)
{
    int comp = 0,curr=0;
    for(int i=N-1;i>=0;i--)
    {
        if(groups[i]>=val)comp++;
        else
        {
            curr+=groups[i];
            if(curr>=val)
            {
                comp++;
                curr= curr - val;
            }
        }
    }

    return (comp>=K);
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/OneDrive/Acads/Contest-Codeforces/input.txt", "r", stdin);
        freopen("/home/om/OneDrive/Acads/Contest-Codeforces/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int K,N;
    cin>>K>>N;

    int groups[N];
    for(int i=0;i<N;i++)cin>>groups[i];

    sort(groups,groups + N);

    int l=1,r=1e17;
    while(l+1<r)
    {
        int mid = (l+r)/2;
        if(good(N,groups,K,mid))l=mid;
        else r=mid;
    }

    cout<<l<<endl;

    return 0;
}