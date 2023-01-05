class Solution {
public:
    int strToDec(string s){
        int val = 0;
        bool neg = false;
        for(int i=0;i<s.size();i++){
            if(s[i]=='-'){
                neg = true;
                continue;
            }
            val = val*10 + (s[i]-'0');
        }
        if(neg){
            val = -val;
        }
        return val;
    }
    int evalRPN(vector<string>& x) {
        int n = x.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(x[i]=="+" || x[i]=="-" || x[i]=="*" || x[i]=="/"){
                int b = st.top();st.pop();
                int a = st.top();st.pop();
                int val = 0;
                if(x[i]=="+")val = a+b;
                else if(x[i]=="-")val = a-b;
                else if(x[i]=="*")val = a*b;
                else val = a/b;
                cout << a << " " << b << " " << val << endl;
                st.push(val);
            }else{
                int val = strToDec(x[i]);
                st.push(val);
            }
        }
        return st.top();
    }
};