#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=(int)s2.length();
        int window_size = (int)s1.length();
        if(n==0 || n<window_size) return false;
        int left = 0;
        int right = left+window_size-1;
        vector<int> mp_s1(26);
        vector<int> mp_s2(26);
        for(auto x : s1){
            mp_s1[x-'a']++;
        }
        while(left <= right){
            mp_s2[s2[left]-'a']++;
            left++;
        }
        if(mp_s1==mp_s2) return true;
        left=0;right=left+window_size-1;
        while(right<n-1 && left<=right){
            cout<<"left="<<left<<" right="<<right<<"\n";
            mp_s2[s2[left]-'a']--;
            left++;
            right++;
            mp_s2[s2[right]-'a']++;
            if(mp_s1==mp_s2) return true;
        }
        return false;
    }
};

int main(){
    FAST_IO;
    Solution s;
    cout<<s.checkInclusion("ab", "eidboaoo")<<"\n";
    return 0;
}
