#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll getSubtreeSize(ll n, ll node) {
    ll size = 0;
    ll left = node;
    ll right = node;
    ll level = 1;
    
    while (left <= n) {
        size += min(right, n) - left + 1;
        left = left * 2;
        right = right * 2 + 1;
    }
    return size;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    
    if (k == 1) {
        // Only root can hold the smallest element
        cout << 1 << '\n';
        return;
    }
    
    ll result = 0;
    ll current = 1;
    
    // Check all nodes level by level
    while (current <= n) {
        ll left = current;
        ll right = min(n, current * 2 - 1);
        bool found = false;
        
        while (left <= right) {
            ll mid = (left + right) / 2;
            ll subtreeSize = getSubtreeSize(n, mid);
            
            if (subtreeSize >= k) {
                // This node and all nodes to the right in this level might be valid
                found = true;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        if (found) {
            // All nodes from current to right in this level are valid
            ll validInLevel = min(n, current * 2 - 1) - current + 1;
            result += validInLevel;
        }
        
        current *= 2;
    }
    
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    solve();
    return 0;
}