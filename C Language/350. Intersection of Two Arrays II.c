

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int **list=(int **)calloc(2,sizeof(int*));
    for(int y=0;y<2;y++){
        list[y]=(int *)calloc(1001,sizeof(int));
    }  
    for(int x=0;x<nums1Size;x++){
        list[0][nums1[x]]+=1;
    }
    for(int x=0;x<nums2Size;x++){
        list[1][nums2[x]]+=1;
    }
    int *answer=(int *)calloc(1001,sizeof(int));
    int cnt=0;
    for(int x=0;x<1001;x++){
        if(list[0][x]>0 && list[1][x]>0){
            int min=list[0][x]>=list[1][x]?list[1][x]:list[0][x];
            for(int y=0;y<min;y++){
                answer[cnt++]=x;
            }
        }
    }
    *returnSize=cnt;
    return answer;
}