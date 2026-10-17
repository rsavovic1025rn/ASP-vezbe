#include <bits/stdc++.h>
using namespace std;
//https://petlja.org/sr-Latn-RS/biblioteka/r/Zbirka2/istorija_pregledaca
int main() {
    stack<string> stek;
    string s;
    while (getline(cin, s) && !s.empty()) {
        if(s == "back") {
            if(!stek.empty())stek.pop();
            if(!stek.empty())cout << stek.top() << endl;
            else cout << "-" << endl;
        }
        else{
            stek.push(s);
            cout << stek.top() << endl;
        }
    }
}