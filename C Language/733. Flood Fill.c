

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int y_max=0;
int x_max=0;
void floodfill(int **image,int y,int x,int color,int pick){
    if(color==pick){
        return;
    }
    image[y][x]=color;
    if(x>0 && image[y][x-1]==pick){
        floodfill(image,y,x-1,color,pick);
    }
    if(y>0 && image[y-1][x]==pick){
        floodfill(image,y-1,x,color,pick);
    }
    if(x<x_max-1 && image[y][x+1]==pick){
        floodfill(image,y,x+1,color,pick);
    }
    if(y<y_max-1 && image[y+1][x]==pick){
        floodfill(image,y+1,x,color,pick);
    }
}
int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes){
    y_max=imageSize;
    x_max=imageColSize[0];
    *returnSize=imageSize;
    *returnColumnSizes=(int *)malloc(imageSize*sizeof(int));
    for(int y=0;y<imageSize;y++){
        (*returnColumnSizes)[y]=imageColSize[y];
    }
    int pick=image[sr][sc];
    floodfill(image,sr,sc,color,pick);
    return image;
}