#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    deque<int> dq;
    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        int elem;
        cin>>elem;
        dq.push_back(elem);
    }

    int curr = 1;
    while(dq.size())
    {
        int l = dq.front();
        int r = dq.back();
        if(l != curr && r!= curr)
        {
            cout << "NO\n";
            return;
        }

        if(l == curr)
        {
            dq.pop_front();
        }
        else
        {
            dq.pop_back();
        }

        curr++;
    }

    cout << "YES\n";
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