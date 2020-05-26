//#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class Solution {
public:
    void FillMap(vector<int> &v,map<int,vector<int>>&mp){
        for(int i=0;i<v.size();i++){
            mp[v[i]].push_back(i);
        }
    }
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int lenA = (int)A.size();
        int lenB = (int)B.size();
        vector<vector<int>>dp(lenA+1,vector<int>(lenB+1));
        for(int i=0;i<lenA+1;i++){
            for(int j=0;j<lenB+1;j++){
                if(i==0||j==0) dp[i][j]=0;
                else if(A[i-1]==B[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[lenA][lenB];
    }
};

//driver code
int main(){
    FAST_IO;
    Solution s;
    vector<int> A = {2,5,1,2,5};
    vector<int> B = {10,5,2,1,5,2};
    cout<<s.maxUncrossedLines(A, B)<<"\n";
    return 0;
}
