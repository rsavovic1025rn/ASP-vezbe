#include <bits/stdc++.h>
using namespace std;
//https://petlja.org/sr-Latn-RS/biblioteka/r/Zbirka2/najblizi_veci_sledbenik
int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0;i<n;i++)cin>>a[i];
    stack<int> stek;
    vector<int> res(n);
    for(int i = n-1;i>=0;i--) {
        while(!stek.empty() && a[i] >= stek.top()) {
            stek.pop();
        }
        if(stek.empty())res[i]=-1;
        else {
            res[i]=stek.top();
        }
        stek.push(a[i]);
    }
    for(int i = 0;i<n;i++) {
        if(res[i]!=-1)cout << res[i] << " ";
        else cout << "- ";
    }
}