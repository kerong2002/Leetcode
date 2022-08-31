

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int *answer=(int *)calloc(digitsSize+1,sizeof(int));
    int carry=0;
    for(int x=digitsSize-1;x>=0;x--){
        if(x==digitsSize-1){
            carry=(digits[x]+1)/10;
            digits[x]=(digits[x]+1)%10;
        }
        else{
            int old=carry;
            carry=(digits[x]+carry)/10;
            digits[x]=(digits[x]+old)%10;
        }
    }
    if(carry>0){
        *returnSize=digitsSize+1;
        int *answer=(int *)calloc(digitsSize+1,sizeof(int));
        answer[0]=carry;
        for(int x=0;x<digitsSize;x++){
            answer[x+1]=digits[x];
        }
        return answer;
    }
    else{
        *returnSize=digitsSize;
        return digits;
    }
}