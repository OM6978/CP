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

    int arr1[N+1],arr2[M+1],arr3[M+N+2];

    for(int i=0;i<N;i++)cin>>arr1[i];
    for(int i=0;i<M;i++)cin>>arr2[i];
    arr1[N] = INT32_MAX;
    arr2[M] = INT32_MAX; 

    int i=0,j=0;
    for(int k=0;k<M+N+2;k++)arr3[k] = (arr1[i] <= arr2[j])?arr1[i++]:arr2[j++];

    for(int k=0;k<M+N;k++)cout<<arr3[k]<<spc;
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