class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        for(char c:s){
            if(c!=']')st.push(c);
            else{
                string curr;
                while(st.top()!='['){
                    curr=st.top()+curr;
                    st.pop();
                }
                st.pop();
                string number="";
                while(!st.empty()&&isdigit(st.top())){
                    number=st.top()+number;
                    st.pop();
                }
                int n=stoi(number);
                while(n--)
                    for(char d:curr)
                        st.push(d);
            }
        }
        s = "";
        while(!st.empty()){
            s=st.top()+s;
            st.pop();
        }
        return s;
    }
};