class Solution {
public:
    string reverseWords(string s) {
        string s1="";
        stack<char> stk;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                while(!stk.empty()){
                    s1+=stk.top();
                    stk.pop();
                }
                s1+=' ';
            }
            else{
                stk.push(s[i]);
            }
        }
        while(!stk.empty()){
            s1+=stk.top();
            stk.pop();
        }
        s=s1;
        return s;
    }
};