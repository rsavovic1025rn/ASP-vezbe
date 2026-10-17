#include <bits/stdc++.h>
//https://petlja.org/sr-Latn-RS/biblioteka/r/Zbirka2/uparenost_zagrada
using namespace std;
bool check(char c1, char c2) {
    if(c2==')' && c1!='(')return false;
    if(c2==']' && c1!='[')return false;
    if(c2=='}' && c1!='{')return false;
    return true;
}
int main() {
    string s;
    cin>>s;
    stack<char> stek;
    int n = s.length();
    for(int i = 0;i<n;i++) {
        if(s[i]=='[' || s[i]=='(' || s[i]=='{') {
            stek.push(s[i]);
            continue;
        }
        if(s[i]==']' || s[i]==')' || s[i]=='}') {
            if(stek.size() > 0 && check(stek.top(), s[i])) {
                stek.pop();
                continue;
            }
            else {
                cout << "ne" << endl;
                return 0;
            }
        }
    }
    if(stek.size()==0) cout << "da" << endl;
    else cout << "ne" << endl;
}