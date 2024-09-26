#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void createTree(TreeNode* bst, int value) {
    if (bst->val<value) {
        if(bst->left!=nullptr) {
            bst->left=new TreeNode(value);
        }
        else createTree(bst->left,value);
    }
    if (bst->val>value) {
        if(bst->right!=nullptr) {
            bst->right=new TreeNode(value);
        }
        else createTree(bst->right,value);
    }
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    if(nums.size()==0) return nullptr;
    int x=nums.size()/2;
    TreeNode bst(nums[x]);
    for (auto i:nums) {
        if(i!=x) {
            createTree(&bst,i);
        }
    }
    return bst;
}


int main() {
    vector<int> nums={-10,-3,0,5,9};
    sortedArrayToBST(nums);
}