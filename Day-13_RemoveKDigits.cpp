class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        if(n==k)return "0";
        stack<char> st;
            for(char c : num){
                while(k>0 && !st.empty() && int(st.top())>int(c)){
                    st.pop();
                    k--;
                } 
                st.push(c);
            } 
            if(k){
                while(k--){
                    st.pop();
                }
            }
            stack<char> st1;
            while(!st.empty()){
                st1.push(st.top());
                st.pop();
            }
            while(st1.top()=='0'&&st1.size()!=1){
                st1.pop();
            }
            num="";
            while(!st1.empty()){
                num.push_back(st1.top());
                st1.pop();
            }
            return num;
        }
};
int main(){
    FAST_IO;
    string n = "1432219";
    Solution s;
    cout<<s.removeKdigits(n, 3)<<"\n";
    return 0;
}
