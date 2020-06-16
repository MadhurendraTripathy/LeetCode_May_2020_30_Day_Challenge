#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class Solution {
public:
    int findMaxLength(vector<int>& nums){
        map<int, int>mp;//map<index,count>
        int mx=0,count = 0;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++){
            nums[i]==1?count++:count--;
            if(mp.find(count)==mp.end()){
                mp[count]=i;
            }
            else{
                mx=max(mx,i-mp[count]);
            }
        }
        return mx;
    }
};

//driver code
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution s;
    vector<int>v={0,1,0};
    cout<<s.findMaxLength(v)<<"\n";
    return 0;
}
