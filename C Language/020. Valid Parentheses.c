

bool isValid(char * s){
    if(strlen(s)==1) return false;
    char stack[10001]={'\0'};
    int top=0;
    for(int x=0;x<strlen(s);x++){
        if(s[x]=='(' || s[x]=='[' || s[x]=='{'){
            stack[top]=s[x];
            top+=1;
        }
        else if(s[x]==')'){
            if(top-1<0){
                return false;
            }
            if(stack[top-1]=='('){
                top-=1;
                stack[top]='\n';
            }
            else{
                return false;
            }
        }
        else if(s[x]==']'){
            if(top-1<0){
                return false;
            }
            if(stack[top-1]=='['){
                top-=1;
                stack[top]='\n';
            }
            else{
                return false;
            }
        }
        else if(s[x]=='}'){
            if(top-1<0){
                return false;
            }
            if(stack[top-1]=='{'){
                top-=1;
                stack[top]='\n';
            }
            else{
                return false;
            }
        }
    }
    if(top!=0){
        return false;
    }
    return true;
}