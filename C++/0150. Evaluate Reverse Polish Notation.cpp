class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>  s;
        for(int x=0;x<tokens.size();x++){
            if(isdigit(tokens[x][tokens[x].length()-1])){
                s.push(stoi(tokens[x]));
            }
            else{
                int top2 = s.top();
                s.pop();
                int top1 = s.top();
                s.pop();
                int ans = 0;
                switch(tokens[x][0]){
                    case '+':
                        ans = top1 + top2;
                        break;    
                    case '-':
                        ans = top1 - top2;
                        break;
                    case '*':
                        ans = top1 * top2;
                        break;
                    case '/':
                        ans = top1 / top2;
                        break;
                }
                s.push(ans);
            }
        }
        return s.top();
    }
};