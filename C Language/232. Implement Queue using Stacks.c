


typedef struct node{
    int val;
    struct node *next;
    struct node *previous;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue *save=(MyQueue *)malloc(sizeof(MyQueue));
    save->val=-1;
    save->previous=NULL;
    save->next=NULL;
    return save;
}

void myQueuePush(MyQueue* obj, int x) {
    MyQueue *save=(MyQueue *)malloc(sizeof(MyQueue));
    save->val=x;
    save->previous=NULL;
    save->next=NULL;
    if(obj==NULL){
        obj=save;
    }
    else{
        MyQueue *set=obj;
        for(set = obj;set->previous!=NULL;set=set->previous);
        set->previous=save;
        save->next=set;
    }
}

int myQueuePop(MyQueue* obj) {
    MyQueue *save=obj->previous;
    MyQueue *list=obj->previous->previous;
    if(list!=NULL){
        list->next=obj;
        obj->previous=list;
    }
    else {
        obj->previous=NULL;
    }
    return save->val;
}

int myQueuePeek(MyQueue* obj) {
    return obj->previous->val;
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->previous==NULL?true:false;
}

void myQueueFree(MyQueue* obj) {
    obj=NULL;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/