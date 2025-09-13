#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define sp ' '

void solve()
{
    int N;
    cin>>N;

    multiset<int> houses;

    int ar[N];
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        houses.insert(ar[i]);
    }

    int Q;
    cin>>Q;

    for(int i=0;i<Q;i++)
    {
        int temp;
        cin>>temp;

        houses.erase(temp);
    }

    int curr = 0,most = 1;
    int prev = *houses.begin()-1;
    for(int val : houses)
    {
        if(val == prev + 1)
        {
            curr++;
            most = max(most,curr);
        }
        else curr = 1;

        prev = val;
    }

    cout<< most <<endl;
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/OneDrive/Contest-Codeforces/input.txt", "r", stdin);
        freopen("/home/om/OneDrive/Contest-Codeforces/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}