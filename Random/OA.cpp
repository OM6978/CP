#include <bits/stdc++.h>
using namespace std;

int minSum(vector<int> num, int k) {
    priority_queue<int> pq(num.begin(), num.end());

    while (k--) {
        int t = pq.top();
        pq.pop();
        pq.push((t + 1) / 2);
    }

    int s = 0;
    while (!pq.empty()) {
        s += pq.top();
        pq.pop();
    }
    
    return s;
}