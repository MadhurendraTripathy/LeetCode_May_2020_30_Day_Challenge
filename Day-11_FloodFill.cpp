#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pii pair<int,int>
int x4dir[4]={-1,1, 0,0};
int y4dir[4]={ 0,0,-1,1};
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int rows=(int)image.size();
        int cols=(int)image[0].size();
        vector<vector<int>>visited(rows,vector<int>(cols,-1));
        queue<pii> q;
        q.push(make_pair(sr,sc));
        visited[sr][sc]++;
        while(!q.empty()){
            pii parent = q.front();
            q.pop();
            visited[parent.first][parent.second]++;
            for(int d=0;d<4;d++){
                int ni = parent.first+x4dir[d];
                int nj = parent.second+y4dir[d];
                if(ni>=0&&ni<rows&&nj>=0&&nj<cols&&visited[ni][nj]==-1){
                    if(image[ni][nj]==image[sr][sc]){
                        q.push(make_pair(ni,nj));
                        image[ni][nj]=newColor;
                    }
                }
            }
        }
        image[sr][sc]=newColor;
        return image;
    }
};

int main(){
    FAST_IO;
    Solution s;
    vector<vector<int>>v={{1,1,1},{1,1,0},{1,0,1}};
    vector<vector<int>>ans;
    ans = s.floodFill(v, 1, 1, 2);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
