#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define vv_int vector<vector<int>>

void solve()
{
    int N,M;
    cin>>N>>M;

    int arr1[N],arr2[M],arr3[M];
    for(int i=0;i<N;i++)cin>>arr1[i];
    for(int i=0;i<M;i++)cin>>arr2[i];

    int i=0,currcount = 0,flag=0;
    for(int j=0;j<M;j++)
    {
        while(arr2[j] > arr1[i] && flag==0)
        {
            currcount++;
            i++;
            if(i==N)flag=1;
        }
        arr3[j] = currcount;
    }

    for(int k=0;k<M;k++)cout<<arr3[k]<<spc;
    cout<<endl;
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/OneDrive/Acads/Contest-Codeforces/input.txt", "r", stdin);
        freopen("/home/om/OneDrive/Acads/Contest-Codeforces/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    solve();

    return 0;
}