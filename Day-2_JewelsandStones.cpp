#inlcude<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int myJewels=0;
        set<char>jewels;
        for(char c : J){
            jewels.insert(c);
        }
        for(char c : S){
            if(jewels.find(c)!=jewels.end()) myJewels++;
        }
        return myJewels;
    }
};

int main(){
    FAST_IO;
    string J="Aa",S="baBAaA";
    Solution s;
    cout<<s.numJewelsInStones(J, S)<<"\n";
    return 0;
}
