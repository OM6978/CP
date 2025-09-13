#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N;
    cin>>N;

    vector<int> ar(N);
    cin>>ar[0];
    string embed = "D";
    for(int i=1;i<N;i++)
    {
        cin>>ar[i];
        if(ar[i] < ar[i-1])embed.push_back('D');
        else embed.push_back('U');
    }

    int ans = 0;
    int last = 0;
    for(int i=0;i<N;i++)
    {
        int curr = last; 
        if(embed[i] == 'D')
        {
            curr += (i+1);
        }
        else
        {
            curr += 1;
        }

        last = curr;
        ans+=curr;
    }

    cout << ans << '\n';
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