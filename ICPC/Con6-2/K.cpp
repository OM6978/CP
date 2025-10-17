#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll MOD = 1e9+7;

const int maxh = 401;
const int maxw = 401;

ll dp1[maxh][maxw][2];
ll dp2[maxh][maxw][2];
ll dp1prefx[maxh][maxw][2];
ll dp1preff[maxh][maxw][2];
ll dp1prefm[maxh][maxw][2];

void solve()
{
    int h,w;
    cin>>h>>w;

    cout << dp1[h][w][0] << '\n';
}

void fillDp()
{
    dp2[0][0][0] = 0;
    dp2[0][0][1] = 1;
    dp2[0][1][0] = 0;
    dp2[0][1][1] = 1;

    for (int h = 1; h <= 400; h++) {
        dp1[h][1][0] = h % MOD;
        dp1[h][1][1] = 1;
        dp1prefx[h][1][0] = h % MOD;
        dp1prefx[h][1][1] = 1;

        dp1preff[h][1][0] = (1LL * h * (h + 1) / 2) % MOD;
        dp1preff[h][1][1] = h % MOD;

        dp1prefm[h][1][0] = (dp1preff[h][1][0] + (h > 0 ? dp1prefm[h - 1][1][0] : 0)) % MOD;
        dp1prefm[h][1][1] = (dp1preff[h][1][1] + (h > 0 ? dp1prefm[h - 1][1][1] : 0)) % MOD;

        dp2[h][0][0] = 0;
        dp2[h][0][1] = 1;

        dp2[h][1][0] = (dp2[h - 1][1][0] + dp1preff[h][1][0]) % MOD;
        dp2[h][1][1] = (dp2[h - 1][1][1] + dp1preff[h][1][1]) % MOD;
    }

    for (int w = 1; w <= 400; w++) {
        dp1[1][w][0] = w % MOD;
        dp1[1][w][1] = 1;
        dp1prefx[1][w][0] = w % MOD;
        dp1prefx[1][w][1] = 1;

        dp1preff[1][w][0] = (1LL * w * (w + 1) / 2) % MOD;
        dp1preff[1][w][1] = w % MOD;

        dp1prefm[1][w][0] = dp1preff[1][w][0];
        dp1prefm[1][w][1] = dp1preff[1][w][1];

        dp2[0][w][0] = 0;
        dp2[0][w][1] = 1;

        dp2[1][w][0] = (dp2[1][w - 1][0] + dp1prefm[1][w][0]) % MOD;
        dp2[1][w][1] = (dp2[1][w - 1][1] + dp1prefm[1][w][1]) % MOD;
    }

    for (int h = 2; h <= 400; h++) {
        for (int w = 2; w <= 400; w++) {
            dp1[h][w][1] = dp2[h - 2][w - 2][1] % MOD;

            dp1[h][w][0] = (dp2[h - 2][w - 2][0] + (1LL * dp1[h][w][1] * h % MOD * w % MOD)) % MOD;

            dp1prefx[h][w][0] = (dp1prefx[h][w - 1][0] + dp1[h][w][0]) % MOD;
            dp1prefx[h][w][1] = (dp1prefx[h][w - 1][1] + dp1[h][w][1]) % MOD;

            dp1preff[h][w][0] = (dp1preff[h - 1][w][0] + dp1prefx[h][w][0]) % MOD;
            dp1preff[h][w][1] = (dp1preff[h - 1][w][1] + dp1prefx[h][w][1]) % MOD;

            dp1prefm[h][w][0] = (dp1prefm[h - 1][w][0] + dp1preff[h][w][0]) % MOD;
            dp1prefm[h][w][1] = (dp1prefm[h - 1][w][1] + dp1preff[h][w][1]) % MOD;

            dp2[h][w][0] = (dp2[h][w - 1][0] + dp1prefm[h][w][0]) % MOD;
            dp2[h][w][1] = (dp2[h][w - 1][1] + dp1prefm[h][w][1]) % MOD;
        }
    }
}


signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/CP/input.txt", "r", stdin);
        freopen("/home/om/Acads/CP/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    fillDp();
    solve();

    return 0;
}