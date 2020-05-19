#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=(int)s.length();
        int window_size = (int)p.length();
        if(n==0 || n<window_size) return {};
        vector<int>ans;
        int left = 0;
        int right = left+window_size-1;
        vector<int> mp_s(26);
        vector<int> mp_p(26);
        for(auto x : p){
            mp_p[x-'a']++;
        }
        while(left <= right){
            mp_s[s[left]-'a']++;
            left++;
        }
        if(mp_s==mp_p) ans.push_back(0);
        
        left=0;right=left+window_size-1;
     
        while(right<n-1 && left<=right){
            cout<<"left="<<left<<" right="<<right<<"\n";
            mp_s[s[left]-'a']--;
            left++;
            right++;
            mp_s[s[right]-'a']++;
            if(mp_s==mp_p) ans.push_back(left);
        }
        return ans;
    }
};

int main(){
    FAST_IO;
    Solution s;
    vector<int> ans = s.findAnagrams("abab", "ab");
    for(auto x : ans){
        cout<<x<<" ";
    }
    cout<<"\n";
    return 0;
}
