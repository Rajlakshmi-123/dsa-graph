#include <iostream>
#include <vector>
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

    root->left = buildTree();
    root->right = buildTree();

    return root;
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;

    if (root == NULL)
        return ans;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();

        for (int i = 0; i < n; i++) {
            TreeNode* cur = q.front();
            q.pop();

            if (i == n - 1)
                ans.push_back(cur->val);

            if (cur->left)
                q.push(cur->left);

            if (cur->right)
                q.push(cur->right);
        }
    }

    return ans;
}

int main() {
    cout << "Enter tree in preorder (-1 for NULL):\n";

    TreeNode* root = buildTree();

    vector<int> ans = rightSideView(root);

    cout << "Right Side View: ";

    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}