#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void PrintLevelOrder(TreeNode * root){
    if(root){
        queue<TreeNode * >q;
        q.push(root);
        while (!q.empty()) {
            TreeNode * currentNode  = q.front();
            q.pop();
            if(currentNode){
                cout<<currentNode->val<<" ";
                q.push(currentNode->left);
                q.push(currentNode->right);
            }
            else{
                cout<<"NULL ";
            }
        }
        cout<<"\n";
    }
}



class Solution {
public:
    TreeNode * CreateNode(int x){
        TreeNode * newnode = new TreeNode(x);
        return newnode;
    }
    void InsertIntoTree(TreeNode * root,int x){
        if(x<=root->val){
            if(root->left){
                InsertIntoTree(root->left, x);
            }
            else{
                root->left = CreateNode(x);
            }
        }
        else{
            if(root->right){
                InsertIntoTree(root->right, x);
            }
            else{
                root->right = CreateNode(x);
            }
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode * root = NULL;
        for(auto x : preorder){
            if(root==NULL){
                root = CreateNode(x);
            }
            else{
                InsertIntoTree(root,x);
            }
        }
        return root;
    }
};

//driver code
int main(){
    FAST_IO;
    Solution s;
    vector<int> v = {8,5,1,7,10,12};
    TreeNode * root = s.bstFromPreorder(v);
    PrintLevelOrder(root);
    return 0;
}
