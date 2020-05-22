#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class Solution {
public:
    string frequencySort(string s) {
        map<int,int>mp;
        for(char c : s){
            mp[c-'a']++;
        }
    }
};
class Solution {
    int sum = 0;
    int rows,cols;
public:
    Solution(){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        sum = 0;
    }
    
    bool isValid(int i,int j){
        return (i>=0&&i<rows&&j>=0&&j<cols);
    }
    
    int countSquares(vector<vector<int>>& matrix) {
        rows = (int)matrix.size();
        if(rows==0) return 0;
        cols = (int)matrix[0].size();
        vector<vector<int>>v(rows,vector<int>(cols,0));
        for(int i=0;i<cols;i++){
            v[0][i]=matrix[0][i];
            sum+=v[0][i];
        }
        for(int i=1;i<rows;i++){
            v[i][0]=matrix[i][0];
            sum+=v[i][0];
        }
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(matrix[i][j]==1){
                        int top_left=INT_MAX,left=INT_MAX,top=INT_MAX;
                        top_left = v[i-1][j-1];
                        top = v[i-1][j];
                        left = v[i][j-1];
                        v[i][j] = 1 + min(min(left,top),top_left);
                }
                sum+=v[i][j];
            }
        }
        return sum;
    }
};

int main(){
    FAST_IO;
    Solution s;
    vector<vector<int>>v={  {0,1,1,1},
                            {1,1,1,1},
                            {0,1,1,1}   };
    cout<<s.countSquares(v)<<"\n";
    return 0;
}
