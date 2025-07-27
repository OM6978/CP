#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> primes;
void sieve(int n)
{
    primes.assign(5e5,0);
    vector<bool> prime(n + 1, true);
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    
    int i = 1;
    for (int p = 2; p <= n; p++){
        if (prime[p]){ 
            primes[i] = primes[i-1] + p;
            i++;
        }
    }
}
 
bool good(int k,vector<int> & ar)
{
    int N = ar.size();
    int sum = ar[N-k-1];
    int psum = primes[N-k];

    // cout << sum << ' ' << psum << ' ' << k << '\n';
    return (sum >= psum);
}

void solve()
{
    int N;
    cin>>N;
    
    vector<int> ar(N+1);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    sort(ar.begin(),ar.end(),greater<int>());
    for(int i=1;i<N;i++)
    {
        ar[i] += ar[i-1];
    }

    int l=0,r=N;
    while(l+1<r)
    {
        int mid = (l+r)>>1;
        if(good(mid,ar))r = mid;
        else l = mid;
    }

    cout << l << '\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/CP/input.txt", "r", stdin);
        freopen("/home/om/Acads/CP/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);

    sieve(6e6);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}