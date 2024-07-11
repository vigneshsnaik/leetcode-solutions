class Solution{
public:
        static string reverseParentheses(string & s){
            string st, rev;
            for (char c: s){
                if (c != ')')
                    st.push_back(c);
                else{
                    rev = "";
                    char r = st.back();
                    while (r != '('){
                        rev += r;
                        st.pop_back();
                        r = st.back();
                    }
                    st.pop_back();
                    st += rev;
                }
            }
            return st;
        }
};