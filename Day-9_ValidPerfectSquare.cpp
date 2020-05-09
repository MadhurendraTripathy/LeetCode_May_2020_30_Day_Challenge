#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class Solution {
public:
    bool isPerfectSquare(ull num) {
        if(num==0){
            return !num;
        }
        ull low=1,high=num, mid = low+(high-low)/2;
        while(low<=high){
            ull sq = mid*mid;
            if(sq == num){
                return true;
            }
            else if(sq>num){
                high = mid-1;
            }
            else{
                low=mid+1;
            }
            mid = low+(high-low)/2;
        }
        return false;
    }
};

int main(){
    FAST_IO;
    int n;
    while(cin>>n){
        Solution s;
        s.isPerfectSquare(n)?cout<<"true\n":cout<<"false\n";
    }
    return 0;
}
