#include <bits/stdc++.h>
using namespace std;
//https://petlja.org/sr-Latn-RS/biblioteka/r/Zbirka2/najveci_pravougaonik_u_histogramu
int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0;i<n;i++)cin>>a[i];
    stack<pair<int,int>> s;
    vector<int> nxt(n, n);
    vector<int> prev(n, -1);
    for(int i = n-1;i>=0;i--) {
        while(!s.empty() && a[i] <=  s.top().first)s.pop();
        if(!s.empty())nxt[i]=s.top().second;
        s.push({a[i], i});
    }
    stack<pair<int,int>> s1;
    for(int i = 0;i<n;i++) {
        while(!s1.empty() && a[i] <= s1.top().first)s1.pop();
        if(!s1.empty())prev[i]=s1.top().second;
        s1.push({a[i], i});
    }
    int res = 0;
    for(int i = 0;i<n;i++)res = max(res, a[i] * (nxt[i] - prev[i] - 1));
    cout << res << endl;
}