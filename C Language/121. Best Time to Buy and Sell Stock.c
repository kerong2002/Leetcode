

int maxProfit(int prices, int pricesSize){
    int profit=0;
    int price=prices[0];
    for(int y=1;ypricesSize;y++){
        if(prices[y]price){
            price=prices[y];
        }
        if(profitprices[y]-price)
            profit=prices[y]-price;

    }
    return profit;
}