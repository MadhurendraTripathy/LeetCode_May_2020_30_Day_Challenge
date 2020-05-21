#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void printTreeLevelWise(TreeNode * root){
    queue<TreeNode*>q;
    q.push(root);
    while (!q.empty()) {
        TreeNode * currNode = q.front();
        q.pop();
        if(currNode){
            cout<<"Node : "<<currNode->val<<" ";
            if(currNode->left){
                q.push(currNode->left);
                cout<<"Node Left : "<<currNode->left->val<<" ";
            }
            else{
                cout<<"Node Left : "<<"NULL ";
            }
            if(currNode->right){
                q.push(currNode->right);
                cout<<"Node Right : "<<currNode->right->val<<"\n";
            }
            else{
                cout<<"Node Right : "<<"NULL ";
            }
        }
        cout<<"\n\n";
    }
}

TreeNode* createNode(int x){
    TreeNode *temp = new TreeNode(x);
    return temp;
}

void insertNode(TreeNode* root,int x){
    //left
    if(x<=root->val){
        if(root->left==NULL){
            root->left = createNode(x);
            return;
        }
        else{
            insertNode(root->left, x);
        }
    }
    else{
        if(root->right==NULL){
            root->right = createNode(x);
            return;
        }
        else{
            insertNode(root->right, x);
        }
    }
}

TreeNode* createTree(vector<int> &v){
    TreeNode* root = NULL;
    for(auto x : v){
        if(x==NULL) continue;
        if(root==NULL){
            root = createNode(x);
        }
        else{
            insertNode(root, x);
        }
    }
    return root;
}

class Solution {
    int result;
    int cnt;
public:
    Solution(){
        result = 0;
        cnt=0;
    }
    void inorder(TreeNode * root, int k){
        if(root){
            if(root->left) inorder(root->left, k);
            cnt++;
            if(cnt==k){
                result = root->val;
                return;
            }
            
            if(root->right) inorder(root->right, k);
        }
    }
    
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return result;
    }
    
};

//driver code
int main(){
    FAST_IO;
    Solution s;
    vector<int> v = {5,3,6,2,4,NULL,NULL,1};
    int k = 3;
    TreeNode *root = createTree(v);
    //printTreeLevelWise(root);
    cout<<s.kthSmallest(root, k)<<"\n";
    return 0;
}
