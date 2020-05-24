#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
class Solution {
public:
    bool areIntersecting(vector<int> v1,vector<int> v2){
        return ( (v2[0]>=v1[0] && v2[0]<=v1[1]) || (v1[0]>=v2[0] && v1[0]<=v2[1]) );
    }
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        int ptrA=0,ptrB=0;
        while(ptrA<A.size()&&ptrB<B.size()){
            if(areIntersecting(A[ptrA],B[ptrB])){
                ans.push_back({ max(A[ptrA][0],B[ptrB][0]),min(A[ptrA][1],B[ptrB][1]) });
            }
            A[ptrA][1]>B[ptrB][1]?ptrB++:ptrA++;
        }
        return ans;
    }
};

//driver code
int main(){
    FAST_IO;
    Solution s;
    set<int> s1={0,1,2},s2={1,2,3,4,5};
    vector<vector<int>> A={{0,2},{5,10},{13,23},{24,25}}, B = {{1,5},{8,12},{15,24},{25,26}};
    vector<vector<int>> ans = s.intervalIntersection(A, B);
    for(auto v : ans){
        for(auto x : v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
