#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
TreeNode* buildBST(int* nums, int start, int end) {
    if (start > end) {
        return nullptr;
    }
    
    int mid = start + (end - start) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = buildBST(nums, start, mid - 1);
    root->right = buildBST(nums, mid + 1, end);
    return root;
}
TreeNode* sortedArrayToBST(int* nums, int size) {
    return buildBST(nums, 0, size - 1);
}
void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    printTree(root->left);
    cout << root->val << "  ";
    printTree(root->right);
}
int main() {
    int nums[] = {-10, -3, 0, 5, 9};
    int size = sizeof(nums) / sizeof(nums[0]);

    TreeNode* root = sortedArrayToBST(nums, size);
    cout << "In-order traversal  of the height-balanced BST: ";
    printTree(root);
    cout << endl;

    return 0;
}