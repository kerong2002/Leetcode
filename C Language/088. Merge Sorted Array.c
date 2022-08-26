

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int *answer=(int *)calloc(m+n,sizeof(int));
    for(int x=0;x<m;x++){
        answer[x]=nums1[x];
    }
    for(int y=0;y<n;y++){
        answer[y+m]=nums2[y];
    }
    for(int x=0;x<m+n;x++){
        for(int y=x+1;y<m+n;y++){
            if(answer[x]>answer[y]){
                int temp=answer[x];
                answer[x]=answer[y];
                answer[y]=temp;
            }
        }
    }
    for(int x=0;x<m+n;x++){
        nums1[x]=answer[x];
    }
}