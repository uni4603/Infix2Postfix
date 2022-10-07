#include <bits/stdc++.h>

using namespace std;


int currpre(char c){
    if(c == '^'){
        return 3;
    }
    else if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    else{
        return -1;
    }
}

string In2Post(string s){

    stack<char> st;
    string result;

    for(int i=0; i<s.length(); i++){

        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
           result+=s[i];    
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                result+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while (!st.empty() && currpre(st.top()) > currpre(s[i])){
                result+= st.top();
                st.pop();
            }   
            st.push(s[i]);
        }
    }

    while (!st.empty()){
            result += st.top();
            st.pop();
    }

    return result;
}

int main(){

    string S;
    cout << "Enter the infix expression: ";
    getline (cin, S);
    //cout << "The postfix expresssion is: " << In2Post( "(a-b/c)*(a/k-l) ") << endl;
    cout << "The postfix expresssion is: " << In2Post(S) << endl;
    return 0;

};

