int min(int a,int b){
    return ((a>=b)?b:a);
}

int minCostClimbingStairs(int* cost, int costSize){
    int *sum=(int *)calloc(costSize,sizeof(int));
    sum[0]=cost[0];
    sum[1]=cost[1];
    for(int x=2;x<costSize;x++){
        sum[x]=min(sum[x-1],sum[x-2])+cost[x];
    }
    return min(sum[costSize-1],sum[costSize-2]);
}