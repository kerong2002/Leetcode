//2023/03/20 kerong
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

//=======<binary tree結構>=========
struct TreeNode {
    int val;            //節點的數值
    TreeNode *left;     //節點的左分支
    TreeNode *right;    //節點的右分之
    TreeNode() : val(-1), left(nullptr), right(nullptr) {}      //完全沒有資訊的建構子
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}  //只有數值的建構子
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} //完整資訊的建構子
};

int string_to_int(string str){
    int power = 1;
    int ans = 0;
    for(int x=str.size()-1;x>=1;x--){
        ans += (str[x]-'0') * power;
        power *= 10;
    }
    return ans;
}


//========<每層打印>==============
void level_order(TreeNode *root, const int max_node_cnt){
    int root_cnt = 1;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()){
        if(root_cnt++ > max_node_cnt){
            cout << q.front()->val;
        }
        else{
            cout << q.front()->val << " ";
        }
        if(q.front()->left){
            q.push(q.front()->left);
        }
        if(q.front()->right){
            q.push(q.front()->right);
        }
        q.pop();
    }
}

int main(int argc, char **argv){
    string buffer;          //把切割的緩衝
    string val_data;        //切割後數值
    while(true){
        TreeNode *head = new TreeNode();
        int root_count = -1;          //節點填滿的數量
        bool is_equal = false;        //重複節點問題
        bool end_test = true;
        int node_cnt = 0;
        while(cin>>buffer){
            end_test = false;
            //=======<終止條件>===========//
            if(buffer.size()==2){
                break;
            }
            //======<根據節點資料，做處理>=======//
            buffer[0] = ' ';                   //把(用掉
            buffer[buffer.size()-1] = ' ';     //把)用掉

            int root_val = 0;               //節點數值
            string root_position;           //節點位置資訊

            val_data = buffer.substr(0, buffer.find(","));
            root_val = string_to_int(val_data);                                    //獲取數值
            root_position = buffer.substr(buffer.find(",")+1, buffer.size()-1);    //獲取位置


            TreeNode *node = head;                //獲取頭資料

            if(root_position.size() == 1){          //最根部處理
                if(node->val == -1){
                    node->val = root_val;
                    root_count += 1;                //找到根部填充
                }
                else{
                    is_equal = true;                //找到重複根部
                }
            }
            else{
                for(int x=0;x<root_position.size()-1;x++){
                    if(root_position[x]=='L'){                  //往左探索
                        if(node->left==NULL){
                            TreeNode *temp = new TreeNode();
                            node->left = temp;
                            node = node->left;
                            root_count -= 1;                    //空的節點
                        }
                        else{
                            node = node->left;
                        }
                    }
                    else if(root_position[x]=='R'){             //往右探索
                        if(node->right==NULL){
                            TreeNode *temp = new TreeNode();
                            node->right = temp;
                            node = node->right;
                            root_count -= 1;                    //空的節點
                        }
                        else{
                           node = node->right;
                        }
                    }
                }

                //======<放到沒有填充的位置>=======//
                if(node->val == -1){
                    node->val = root_val;
                    root_count += 1;
                    node_cnt += 1;
                }
                else{
                    is_equal = true;                //重複的
                }
            }
        }

        if(end_test){
            break;
        }
        //======<存在重複節點>======//
        if(is_equal || root_count!=0){
            cout << "not complete" << endl;
        }
        else{
            //postorder(head);
            level_order(head, node_cnt);
            cout << endl;
        }
    }
    return 0;
}
/*
input:
(11,LL) (7,LLL) (8,R) (5,) (4,L) (13,RL) (2,LLR) (1,RRR) (4,RR) ()
(3,L) (4,R) ()



*/
