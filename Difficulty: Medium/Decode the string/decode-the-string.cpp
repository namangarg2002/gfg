class Solution {
  public:
    string decodedString(string &s) {
        stack<int> count;
        stack<string> strings;
        string curr = "";
        int num = 0;

        for(char ch: s){
            if(ch >= '0' && ch <= '9'){
                num = num*10 + (ch - '0');
            }else if(ch == '['){
                count.push(num);
                strings.push(curr);

                num = 0;
                curr = "";
            }else if(ch == ']'){
                int k = count.top();
                count.pop();

                string prev = strings.top();
                strings.pop();

                string temp = "";
                while(k--){
                    temp = temp + curr;
                }

                curr = prev + temp;
            }else{
                curr += ch;
            }
        }
        return curr;
        
    }
};