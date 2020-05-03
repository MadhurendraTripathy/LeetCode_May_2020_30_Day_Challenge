

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> rN;map<char,int> mg;
        for(auto c : ransomNote){
            rN[c]++;
        }
        for(auto c : magazine){
            mg[c]++;
        }
        for(auto it : rN){
            if(mg.find(it.first)==mg.end()){
                return false;
            }
            if(mg.find(it.first)!=mg.end()){
                if(it.second > mg[it.first]){
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){
    FAST_IO;
    int t;cin>>t;
    Solution s;
    s.canConstruct("aa","ababa")?cout<<"true":"false";
    return 0;
}
