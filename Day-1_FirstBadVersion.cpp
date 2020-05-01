#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

class Solution {
    int badVersion;
public:
    Solution(int badV){
        badVersion = badV;
    }
    bool isBadVersion(int x){
        return x>=badVersion?true:false;
    }
    int firstBadVersion(int n) {
        int low=1;int high=n;
        int mid=low+(high-low)/2;
        while(low<=high){
            cout<<"mid = "<<mid<<"\n";
            bool mid_is_bad = isBadVersion(mid);
            bool mid_prev_bad = isBadVersion(mid-1);
            if( mid_is_bad && !(mid_prev_bad) ) {
                return mid;
            }
            else if(mid_is_bad && mid_prev_bad){
                high = mid;
            }
            else if( (!mid_is_bad) ){
                low=mid+1;
            }
            mid=low+(high-low)/2;
        }
        return -1;
    }
};

int main(){
    FAST_IO;
    Solution s(1000);
    cout<<s.firstBadVersion(1000)<<"\n";
    return 0;
}
