class Solution {
public:
    int precedence(char op){
        if(op == '+' || op == '-'){
            return 1;
        }
        else if(op == '*' || op == '/'){
            return 2;
        }
        else if(op == '('){
            return -1;
        }
        else{
            return 0;
        }
    }

    int Postfix_Calculate(string postfix){
        stack<int> s;
        for(int x=0;x<postfix.size();x++){
            if(isdigit(postfix[x])){
                int check_num = x;
                string int_number = "";
                int_number += postfix[check_num];
                while(isdigit(postfix[++check_num])){
                    int_number += postfix[check_num];
                }

                x += check_num - x - 1;
                s.push(stoi(int_number));
            }
            else if(postfix[x]==' '){
                continue;
            }
            else{
                int top2 = s.top();
                s.pop();
                int top1 = s.top();
                s.pop();
                int ans = 0;
                switch(postfix[x]){
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

    string Infix_to_Postfix(string infix){
        stack<char> operator_c;
        string postfix = "";
        bool is_parentheses = false;
        for(int x=0;x<infix.size();x++){
            char current_op = infix[x];
            if(isdigit(current_op)){
                int check_number = x;
                while(isdigit( infix[check_number])){
                    postfix += infix[check_number];
                    check_number++;
                }
                x +=  check_number - x - 1;
                postfix += " ";
                is_parentheses = false;
            }
            else if(current_op==' '){
                continue;
            }
            else if(current_op=='('){
                operator_c.push(current_op);
                is_parentheses = true;
            }
            else if(current_op==')'){
                while(!operator_c.empty() && operator_c.top()!='('){
                    postfix += operator_c.top();
                    postfix += " ";
                    operator_c.pop();
                }
                operator_c.pop();
            }
            else{
                if(is_parentheses || x==0){
                    if(current_op=='-'){
                        postfix += "0 ";
                    }
                }
                while(!operator_c.empty() && precedence(current_op) <= precedence(operator_c.top())){
                    postfix += operator_c.top();
                    postfix += " ";
                    operator_c.pop();
                }
                operator_c.push(current_op);
            }
        }
        while(!operator_c.empty()){
            postfix += operator_c.top();
            operator_c.pop();
        }
        return postfix;
    }
    int calculate(string s) {
        string postfix = Infix_to_Postfix(s);
        return Postfix_Calculate(postfix);
    }
};