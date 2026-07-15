#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

TreeNode* buildTree() {
    int x;
    cin >> x;

    if (x == -1)
        return NULL;

    TreeNode* root = new TreeNode(x);

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        int leftVal, rightVal;
        cin >> leftVal;

        if (leftVal != -1) {
            curr->left = new TreeNode(leftVal);
            q.push(curr->left);
        }

        cin >> rightVal;

        if (rightVal != -1) {
            curr->right = new TreeNode(rightVal);
            q.push(curr->right);
        }
    }

    return root;
}

int findHeight(TreeNode* root, int &diameter) {
    if (root == NULL)
        return 0;

    int leftHeight = findHeight(root->left, diameter);
    int rightHeight = findHeight(root->right, diameter);

    diameter = max(diameter, leftHeight + rightHeight);

    return 1 + max(leftHeight, rightHeight);
}

int diameterOfTree(TreeNode* root) {
    int diameter = 0;
    findHeight(root, diameter);
    return diameter;
}

int main() {

    cout << "Enter tree in level order (-1 for NULL):" << endl;

    TreeNode* root = buildTree();

    cout << "Diameter of Tree = " << diameterOfTree(root) << endl;

    return 0;
}