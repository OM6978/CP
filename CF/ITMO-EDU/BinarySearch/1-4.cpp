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
    
    int N;
    cin>>N;
    int ar[N];
    for(int i=0;i<N;i++)cin>>ar[i];
    sort(ar,ar+N);
    vector<int> A(ar,ar+N);

    int K,a,b;
    cin>>K;
    for(int i=0;i<K;i++)
    {
        cin>>a>>b;
        auto low = lower_bound(A.begin(),A.end(),a) - A.begin();
        auto high = upper_bound(A.begin(),A.end(),b) - A.begin();
        cout<< high-low<<endl;
    }
    return 0;
}