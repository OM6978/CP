#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
// Exact nCr using integer arithmetic with __int128
int nCr(int n, int r) {
    if (r > n) return 0;
    r = min(r, n - r);
    if (r == 0) return 1;
    __int128 res = 1;
    for (int i = 1; i <= r; ++i) {
        res = res * (n - r + i) / i; // exact division at each step
    }
    return (int)res;
}
 
int limSolve(int N, int K, const vector<int> &ar, int in, long long l, long long r) {
    // When no more boxes to pick, count 1 only if sum 0 lies in [l, r]
    if (K == 0) {
        return (l <= 0 && 0 <= r) ? 1 : 0;
    }
 
    int ulin = in - 1;
    for (int i = in; i < N; ++i) {
        if (ar[i] < l) break;                // all further will be < l
        if (ar[i] <= r) { ulin = i; break; } // first element within upper bound
    }
 
    int llin = N;
    for (int i = in; i < N; ++i) {
        if (ar[i] < l) { llin = i; break; }  // first element < lower bound
    }
 
    long long ans = 0;
    // For indices between ulin+1 and llin-1,
    // count combinations where chosen element is strictly between indexes
    for (int i = ulin + 1; i < llin; ++i) {
        ans += nCr(N - i - 1, K - 1);
    }
 
    // If there is an element ar[ulin] that lies in [l, r], try selecting it
    if (ulin >= in) {
        ans += limSolve(N, K - 1, ar, ulin + 1, 0, r - ar[ulin]);
    }
    // If there is an element ar[llin] that is < l, try selecting it (shifts interval)
    if (llin < N) {
        ans += limSolve(N, K - 1, ar, llin + 1, l - ar[llin], r - ar[llin]);
    }
 
    return (int)ans;
}
 
void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;
    vector<int> ar(N);
    for (int i = 0; i < N; ++i) cin >> ar[i];
 
    sort(ar.begin(), ar.end(), greater<int>());
 
    long long A, B;
    cin >> A >> B;
 
    cout << limSolve(N, K, ar, 0, A, B) << '\n';
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