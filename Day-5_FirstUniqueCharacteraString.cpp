#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>mp;
        for(auto c : s){
            mp[c]++;
        }
        for(int i=0;s[i]!='\0';i++){
            if(mp[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    FAST_IO;
    string str = "leetcode";
    Solution s;
    cout<<s.firstUniqChar(str)<<"\n";
    return 0;
}
