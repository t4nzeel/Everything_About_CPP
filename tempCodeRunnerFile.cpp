int n=s.size();
    stack<char>st;
    int cnt=0;
    for(char c:s){
        if(st.empty()){
            st.push(c);
            continue;
        }
        if(c==')' && st.top()=='(')st.pop();
        else if(c=='(' || c==')')st.push(c);
        else cnt++;
    }
    while(!st.empty() && cnt!=0){
        cnt--;
        st.pop();
    }
    if(!st.empty())return false;
    return true;