#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/minimum-size-subarray-sum/description/
int minSubArrayLen(int target, vector<int>& nums) {
    queue<int> red;
    int trenutno = 0;
    int n = nums.size();
    int res = n;
    int total = 0;
    for(int i = 0;i<n;i++){
        trenutno+=nums[i];
        total+=nums[i];
        red.push(nums[i]);
        while(trenutno >= target){
            res = min(res, (int)red.size());
            trenutno-=red.front();
            red.pop();
        }
    }
    if(total<target)return 0;
    return res;
}
int main() {

}