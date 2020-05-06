#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n = (int)nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>(n/2)){
                return nums[i];
            }
        }
        return -1;
    }
};
int main(){
    FAST_IO;
    Solution s;
    vector<int>v={3,2,3};
    cout<<s.majorityElement(v)<<"\n";
    return 0;
}
