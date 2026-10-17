#include <bits/stdc++.h>
using namespace std;
//https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
string firstNonRepeating(string &s) {
    string res;
    vector<int> cnt(30, 0);
    queue<char> red;
    int n = s.length();
    for(int i = 0;i<n;i++){
        cnt[s[i]-'a']++;
        if(cnt[s[i]-'a']==1)red.push(s[i]);
        while(red.size() > 0 && cnt[red.front() - 'a'] > 1)red.pop();
        if(red.size()==0)res.push_back('#');
        else res.push_back(red.front());
    }
    return res;
}
int main() {

}