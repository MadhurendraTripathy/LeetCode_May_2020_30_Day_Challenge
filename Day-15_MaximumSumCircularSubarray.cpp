#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& a) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int sum=0,n=(int)a.size(),mx=INT_MIN,arr_sum=0,no_of_negatives=0,max_of_all_mini=INT_MIN;
        for(int i=0;i<n;i++){
            max_of_all_mini=max(max_of_all_mini,a[i]);
            if(a[i]<0){
                no_of_negatives++;
            }
            if(no_of_negatives == n) return max_of_all_mini;
            
            sum=max(a[i],sum+a[i]);
            mx=max(mx,sum);
        }
        int max_straight_subarray_sum = mx;
        mx=INT_MIN;sum=0;
        for(int i=0;i<n;i++){
            arr_sum+=a[i];
            a[i]=(-a[i]);
        }
        for(int i=0;i<n;i++){
            sum=max(a[i],sum+a[i]);
            mx=max(mx,sum);
        }
        return max(max_straight_subarray_sum, arr_sum+mx);
    }
};
//driver code
int main(){
    FAST_IO;
    Solution s;
    vector<int> v = {5,-3,5};
    cout<<s.maxSubarraySumCircular(v)<<"\n";
    return 0;
}
