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

TreeNode* CreateNode(int x){
    TreeNode* nn = new TreeNode(x);
    return nn;
}

void insertNode(TreeNode* root,int x){
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()){
        TreeNode *temp = q.front();
        q.pop();
        if(temp->left==NULL){
            temp->left  = CreateNode(x);break;
        }
        else{
            q.push(temp->left);
        }
        if(temp->right==NULL){
            temp->right  = CreateNode(x);break;
        }
        else{
            q.push(temp->right);
        }
    }
}

TreeNode* ConstructTree(vector<int> v){
    TreeNode* root=NULL;
    if(v.empty()) return root;
    if(root==NULL){
        root=CreateNode(v[0]);
    }
    if(v.size()==1){
        return root;
    }
    for(int i=1;i<v.size();i++){
        insertNode(root, v[i]);
    }
    return root;
}

class Solution {
public:
    //map<val, pair<depth,parent>>;
    map<int, pair<int, int> >mp;
    void parent_and_depth(TreeNode *root, int depth, int parent){
        if(root==NULL) return;
        mp[root->val] = make_pair(depth, parent);
        parent_and_depth(root->left, depth+1, root->val);
        parent_and_depth(root->right, depth+1, root->val);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        parent_and_depth(root, 0, root->val);
        return ((mp[x].first==mp[y].first)&&(mp[x].second!=mp[y].second));
    }
};

int main(){
    FAST_IO;
    vector<int>v={1,2,3,4,5,6};
    TreeNode* root = ConstructTree(v);
    Solution s;
    s.isCousins(root, 5, 6)?cout<<"true\n":cout<<"false\n";
    return 0;
}
