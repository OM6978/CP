#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;
const int nP = 3;
const int primes[nP] = {31, 37, 43};

int power(int x, int y, int p)
{
    int res = 1;
    while (y > 0)
    {
        if (y % 2 == 1)
        res = (res * x)%p;

        y = y >> 1;
        x = (x * x) % p;
    }
    return res % p;
}

void solve()
{
    string s;
    string pat;

    cin>>s;
    cin>>pat;

    int M = pat.size();
    int N = s.size();

    vector<vector<int>> rkArr(N,vector<int>(nP));
    
    vector<int> st(nP,0);

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<nP;j++)
        {
            int p = primes[j];
            st[j] = ((st[j]*p)%MOD + (s[i] - 'a' + 1))%MOD;
            rkArr[i][j] = st[j];
        }
    }

    vector<int> ag(nP,0);
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<nP;j++)
        {
            int p = primes[j];
            ag[j] = ((ag[j]*p)%MOD + (pat[i] - 'a' + 1))%MOD;
        }
    }

    int ans = 0;
    st.assign(nP,0);

    vector<int> mult(nP);
    for(int j=0;j<nP;j++)
    {
        int p = primes[j];
        mult[j] = power(p,M,MOD);
    }

    for(int i=M-1;i<N;i++)
    {
        bool eq = true;
        for(int j=0;j<nP;j++)
        {
            int comp = (rkArr[i][j] - st[j] + MOD)%MOD;
            eq = eq && (comp == ag[j]);
            st[j] = (rkArr[i - M + 1][j]*mult[j])%MOD;
        }

        if(eq)ans++;
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
    
    solve();

    return 0;
}