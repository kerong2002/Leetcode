

int maxProfit(int* prices, int pricesSize){
    int total=0;
    for(int x=1;x<pricesSize;x++){
        if((prices[x]-prices[x-1])>0){
            total+=prices[x]-prices[x-1];
        }
    }
    return total;
}