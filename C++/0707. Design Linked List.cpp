struct node{
    int val;
    node *next;
};

class MyLinkedList {
private:
    node *head;
    int node_amount;
public:
    MyLinkedList() {
       head = nullptr;
       node_amount = -1;
    }

    int get(int index) {
        if(node_amount < index){
            return -1;
        }
        else{
            int cnt = 0;
            node *startNode = head;
            while(cnt < index){
                cnt += 1;
                startNode = startNode->next;
            }
            return startNode->val;
        }
    }

    void addAtHead(int val) {
        node *newNode = new node;
        newNode->val = val;
        newNode->next = nullptr;
        node_amount += 1;
        if(head == nullptr){
            head = newNode;
            return;
        }
        else{
            newNode->next = head;
            head = newNode;
            return;
        }
    }

    void addAtTail(int val) {
        node *newNode = new node;
        newNode->val = val;
        newNode->next = nullptr;
        node_amount += 1;
        if(head == nullptr){
            head = newNode;
            return;
        }
        else{
            node *startNode = head;
            while(startNode->next != nullptr){
                startNode = startNode->next;
            }
            startNode->next = newNode;
            return;
        }
    }

    void addAtIndex(int index, int val) {
        if(index < 0 || node_amount+1 < index){
            return;
        }
        else if(index == 0){
            addAtHead(val);
        }
        else if(index == node_amount+1){
            addAtTail(val);
        }
        else{
            int cnt = 0;
            node *startNode = head;
            node *newNode = new node;
            newNode->val = val;
            newNode->next = nullptr;
            node_amount += 1;
            while(cnt < index-1){
                startNode = startNode->next;
                cnt += 1;
            }

            node *endNode = startNode->next;
            startNode->next = newNode;
            newNode->next = endNode;
        }
    }

    void deleteAtIndex(int index) {
        if(index < 0 || node_amount < index){
            return;
        }
        else if(index == 0){
            node *pre = head;
            head = head->next;
            node_amount -= 1;
            delete pre;
            return;
        }
        else{
            int cnt = 0;
            node *preNode = nullptr;
            node *startNode = head;
            node_amount -= 1;
            while(cnt < index){

                preNode = startNode;
                startNode = startNode->next;
                cnt += 1;
            }
            if(startNode->next == nullptr){
                preNode->next = nullptr;
            }
            else{
                preNode->next = startNode->next;
            }
            delete startNode;
            return;
        }
    }
};