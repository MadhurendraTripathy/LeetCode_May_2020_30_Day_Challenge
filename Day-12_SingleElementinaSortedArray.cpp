#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = (int)nums.size()-1;
        int mid = 0;
        while(low<high){
            mid = low+(high-low)/2;
            if(mid&1){ //mid odd
                if(nums[mid-1]==nums[mid]){
                    low = mid+1;
                }
                else{
                    high = mid;
                }
            }
            else{
                if(nums[mid+1]==nums[mid]){
                    low = mid+1;
                }
                else{
                    high = mid;
                }
            }
            mid = low+(high-low)/2;
        }
        return nums[mid];
    }
};

int main(){
    FAST_IO;
    vector<int> v = {3,3,7,7,10,11,11};
    Solution s;
    cout<<s.singleNonDuplicate(v)<<"\n";
    return 0;
}
