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

TreeNode* addNode(vector<int> nums,int x, int y) {
    if (x>y) return nullptr;
    int mid=x+(y-x)/2;
    TreeNode* temp=new TreeNode(nums[mid]);
    temp->left=addNode(nums,x,mid-1);
    temp->right=addNode(nums,mid+1,y);
    return temp;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    if (nums.size()==0) return nullptr;
    return addNode(nums,0,nums.size()-1);
}


int main() {
    vector<int> nums={-10,-3,0,5,9};
    sortedArrayToBST(nums);
}