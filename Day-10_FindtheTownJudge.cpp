#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& v) {
        unordered_map<int,set<int>>mp;
        set<int>st;int setSum=0;int prev_size = 0;
        for(auto v1 : v){
            st.insert(v1[0]);
            int new_size = (int)st.size();
            if(new_size>prev_size){//new ele added
                setSum+=v1[0];
                prev_size = new_size;
            }
        }
        int expected_judge = (N*(N+1)/2)-setSum;
        //cout<<"Expected Judge : "<<expected_judge<<"\n";
        for(auto x : v){
            mp[x[0]].insert(x[1]);
        }
        if(mp[expected_judge].size()>0){
            return -1;
        }
        for(int i=1;i<=N;i++){
            if(i!=expected_judge){
                if(mp[i].find(expected_judge)==mp[i].end()){
                    return -1;
                }
            }
        }
        return expected_judge;
    }
};

int main(){
    FAST_IO;
    Solution s;
    vector<vector<int>>v={{1,2},{2,1}};
    cout<<s.findJudge(2, v)<<"\n";
    return 0;
}
