#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class Solution {
public:
    bool Bipartite(int node , map<int,vector<int>> &adj_mat,vector<int>&color){
        queue<int> q;
        q.push(node);
        color[node]=1;
        while (!q.empty()) {
            int current_node = q.front();
            q.pop();
            for(int neighbour_node : adj_mat[current_node]){
                if(color[current_node]==color[neighbour_node]) return false;
                if(color[neighbour_node]==-1){
                    q.push(neighbour_node);
                    color[neighbour_node]=1-color[current_node]; //if curr_node_color = 1 then neigh_node_col = 0 & vice versa
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        map<int,vector<int>>adj_mat;
        int n = (int)dislikes.size();
        for(int i=0;i<n;i++){
            int ele1 = dislikes[i][0];
            int ele2 = dislikes[i][1];
            adj_mat[ele1].push_back(ele2);
            adj_mat[ele2].push_back(ele1);
        }
        vector<int>color(N+1,-1);
        for(int i=1;i<=N;i++){
            if(color[i]==-1){
                if(!Bipartite(i,adj_mat,color)){
                    return false;
                }
            }
        }
        return true;
    }
};

//driver code
int main(){
    FAST_IO;
    Solution s;
    //vector<vector<int>> v = {{1,2},{2,3},{3,4},{4,5},{1,5}};
    vector<vector<int>> v = {{5,9},{5,10},{5,6},{5,7},{1,5},{4,5},{2,5},{5,8},{3,5}};
    cout<<s.possibleBipartition(9, v)<<"\n";
}
