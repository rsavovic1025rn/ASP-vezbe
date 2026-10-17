#include <bits/stdc++.h>
using namespace std;
//https://petlja.org/sr-Latn-RS/biblioteka/r/Problems/maxStack
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin>>q;
    stack<int> stek;
    stack<int> mx;
    while(q--) {
        int tip;
        cin>>tip;
        if(tip==1) {
            int broj;
            cin>>broj;
            stek.push(broj);
            if(mx.empty()) {
                mx.push(broj);
                continue;
            }
            if(broj >= mx.top())mx.push(broj);
            continue;
        }
        if(tip==2) {
            if(stek.empty())continue;
            int broj = stek.top();
            if(mx.top()==broj)mx.pop();
            stek.pop();
            continue;
        }
        if(tip==3) {
            if(stek.empty())continue;
            cout << stek.top() << '\n';
            continue;
        }
        if(stek.empty())continue;
        cout << mx.top() << '\n';
    }

}