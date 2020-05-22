//Method - 1
class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    }
    string frequencySort(string s) {
        string ans="";
        vector<int> hash_map(256);
        for(char c : s){
            hash_map[(int)c]++;
        }
        vector< pair<int,char> > v;
        for(int i=0;i<256;i++){
            if(hash_map[i]) v.push_back(make_pair(hash_map[i], (char)i));
        }
        sort(v.rbegin(), v.rend());
        for(auto pic : v){
            while(pic.first--){
                ans+=pic.second;
            }
        }
        return ans;
    }
};
//Method - 2
// class Solution {
// public:
//     Solution(){
//         ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//     }
//     string frequencySort(string s) {
//         map<char,int>hash_mp;// pair<freq,char>
//         map< int,vector<char> >revMap;
//         string ans="";
//         for(char c : s){
//             hash_mp[c]++;
//         }
//         map<char,int>::iterator it;
//         for(it = hash_mp.begin();it!=hash_mp.end();it++){
//             revMap[it->second].push_back((it->first));
//         }
//         map<int,vector<char>>::reverse_iterator r_it;
//         for(r_it=revMap.rbegin();r_it!=revMap.rend();r_it++){
//             for(char c : r_it->second){
//                 int cnt = r_it->first;
//                 while(cnt--){
//                     ans+=c;
//                 }
//             }
//         }
//         return ans;
//     }
// };

//driver code
int main(){
    FAST_IO;
    Solution s;
    cout<<s.frequencySort("tree")<<"\n";
    return 0;
}
