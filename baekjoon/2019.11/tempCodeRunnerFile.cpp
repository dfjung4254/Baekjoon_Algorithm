    else if (ch == ')') {
      while(!st.empty() && st.top() != '('){
        result += st.top();
        st.pop();
      }
      st.pop();
    }