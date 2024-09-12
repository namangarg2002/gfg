//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    // if odd sized string then impossible to make pairs
    if(s.size() & 1) return -1;
    
    int ans = 0;
    stack<char> st;
    for(char ch:s){
        if(ch == '{'){
            st.push(ch);
        }else{
            if(!st.empty() && st.top()=='{'){
                st.pop();
            }else{
                st.push(ch);
            }
        }
    }
    int count = 0;
    while(st.size() >= 2){
        char firstLastCharacter = st.top();
        st.pop();
        char secondLastCharacter = st.top();
        st.pop();
        
        if(firstLastCharacter == secondLastCharacter){
            count += 1;
        }else{
            count += 2;
        }
        
    }
    return count;
    
}