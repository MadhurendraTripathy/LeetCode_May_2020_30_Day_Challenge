#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class Solution {
public:
    int findComplement(int num) {
        int exor_with = pow(2,(int)log2(num)+1)-1;
        return (num^exor_with);
    }
};

int main(){
    FAST_IO;
    int n = 5;
    Solution s;
    cout<<s.findComplement(n)<<"\n";
    return 0;
}
