class StockSpanner {
    stack<pair<int,int>> st;
    int idx;
public:
    StockSpanner() {
        idx = -1;
    }
    
    int next(int price){
        idx ++;
        
        while(!st.empty() && st.top().second<=price){
            st.pop();
        }

        if(st.empty()){
            st.push({idx,price});
            return idx+1;
        }
        
        int ans = st.top().first;
        st.push({idx,price});
        return idx-ans;
    }
};

//driver code
int main(){
    FAST_IO;
    StockSpanner* obj = new StockSpanner();
    cout<<obj->next(100)<<"\n";
    cout<<obj->next(80)<<"\n";
    cout<<obj->next(60)<<"\n";
    cout<<obj->next(70)<<"\n";
    cout<<obj->next(60)<<"\n";
    cout<<obj->next(75)<<"\n";
    cout<<obj->next(85)<<"\n";
    return 0;
}
