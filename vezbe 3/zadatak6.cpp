#include <bits/stdc++.h>
using namespace std;
//https://petlja.org/sr-Latn-RS/biblioteka/r/Zbirka2/svi_ispred_manji_ili_svi_ispred_veci
int main() {
    int n;
    cin>>n;
    deque<int> dek;
    int prethodni = -1;
    for(int i = 0;i<n;i++) {
        int broj;
        cin>>broj;
        if(prethodni == -1) {
            dek.push_back(broj);
            prethodni = broj;
            continue;
        }
        if(broj > prethodni) dek.push_back(broj);
        else dek.push_front(broj);
    }
    for(int x : dek)cout << x << " ";
}