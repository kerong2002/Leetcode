
int divide(int dividend, int divisor){
    long long int pick = dividend / (long long int)divisor;
    if(pick >=INT_MAX){
        return INT_MAX;
    }
    else if (pick<=INT_MIN){
        return INT_MIN;
    }
    else{
        return (int)pick;
    }
}