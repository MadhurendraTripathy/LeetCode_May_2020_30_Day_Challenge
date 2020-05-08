#include<bits.stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class Solution {
    double slope;
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size()==2) return true;
        int X2minusX1,Y2minusY1;
        X2minusX1 = coordinates[1][0] - coordinates[0][0];
        Y2minusY1 = coordinates[1][1] - coordinates[0][1];
        int Y1 = coordinates[0][1];
        int X1 = coordinates[0][0];
        for(int i=3;i<coordinates.size();i++){
            int X = coordinates[i][0];
            int Y = coordinates[i][1];
            if( ((X2minusX1) * (Y-Y1)) != ((Y2minusY1)*(X-X1)) ){
                return false;
            }
        }
        return true;
    }
};

int main(){
    FAST_IO;
    Solution s;
    vector<vector<int>>v={{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}};
    //vector<vector<int>>v={{-4,-3},{1,0},{3,-1},{0,-1},{-5,2}};
    s.checkStraightLine(v)?cout<<"true\n":cout<<"false\n";
    return 0;
}
