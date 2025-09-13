#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    string ans;
    int l = 0,r = N-1;
    int last = 0;
    while(l<r)
    {
        if((ar[l] < ar[r] && last < ar[r]) || (ar[r] < ar[l] && last > ar[l]))
        {
            ans.push_back('R');
            ans.push_back('L');
            last = ar[l];
        }
        else
        {
            ans.push_back('L');
            ans.push_back('R');
            last = ar[r];
        }

        l++;
        r--;
    }

    if(l == r)ans.push_back('R');

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