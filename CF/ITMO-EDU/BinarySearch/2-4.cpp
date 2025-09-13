#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define int long long

vector<int> eachballoons;

int findballoons(int x,int y,int z,int time)
{
    int com = x*y + z;
    int ans= y*(time/com),remain = time%com;

    if(remain<=x*y)
    {
        ans+=remain/x;
    }
    else ans+=y;

    return ans;
}

int good(int arr[][3],int time,int n,int m,int flag)
{
    int ans=0;

    for(int i=0;i<n;i++)
    {
        if(flag)
        {
            eachballoons.push_back(min(findballoons(arr[i][0],arr[i][1],arr[i][2],time),m));
            m-=min(findballoons(arr[i][0],arr[i][1],arr[i][2],time),m);
        }
        ans+= findballoons(arr[i][0],arr[i][1],arr[i][2],time);
    }

    return (ans>=m);
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/OneDrive/Acads/Contest-Codeforces/input.txt", "r", stdin);
        freopen("/home/om/OneDrive/Acads/Contest-Codeforces/output.txt", "w", stdout);
    #endif

    eachballoons.clear();

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int m,n;
    cin>>m>>n;

    int skills[n][3];
    for(int i=0;i<n;i++)
    {
        cin>>skills[i][0]>>skills[i][1]>>skills[i][2];
    }

    if(m==0)
    {
        std::cout<<0<<endl;
        cout<<0<<endl;
        return 0;
    }

    int l=-1,r=1e9+1;
    while(l<r-1)
    {
        int mid = (l+r)/2;
        if(good(skills,mid,n,m,0))r=mid;
        else l=mid;
    }

    good(skills,r,n,m,1);

    std::cout<<r<<endl;

    for(int i=0;i<n;i++)
    {
        std::cout<<eachballoons[i]<<space;
    }
    std::cout<<endl;

    return 0;
}