class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
               int ch=s[i];
               if(ch=='('){
                    st.push(')');
               }
               else{
                    if(ch=='{')
                       st.push('}');

                       else if(ch=='[')
                           st.push(']');
                  
               else{
                    if(st.empty())
                        return false;
                     else if(st.top()!=ch)
                          return false;
                          else
                            st.pop();

               }
        }
        }
        if(st.empty())
            return 1;
           return 0; 
    }
};