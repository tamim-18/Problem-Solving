class Solution{
public:
    void Reverse(stack<int> &st){
        if(st.empty()) return;
        int topEl=st.top();
        st.pop();
        Reverse(st);
        insertBottom(st,topEl);
        
    }
    void insertBottom(stack<int>&st,int el){
        if(st.empty()) st.push(el);
        else {
            int topEl=st.top();
            st.pop();
            insertBottom(st,el);
            st.push(topEl);
        }
    }
};