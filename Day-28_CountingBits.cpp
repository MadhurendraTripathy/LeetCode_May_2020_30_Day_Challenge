#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
class Solution {
public:
    vector<int> countBits(int num) {
        if(num==0) return {0};
        vector<int>ans={0,1};
        if(num==1) return ans;
        for(int i=2;i<=num;i++){
            int count = 0;
            int n = i;
            while(n){
                if(n&1){
                    count++;
                }
                n>>=1;
            }
            ans.push_back(count);
        }
        return ans;
    }
};
//driver code
int main(){
    FAST_IO;
    Solution s;
    vector<int>ans = s.countBits(5);
    for(int ele : ans) cout<<ele<<" ";
    cout<<"\n";
    return 0;
}
