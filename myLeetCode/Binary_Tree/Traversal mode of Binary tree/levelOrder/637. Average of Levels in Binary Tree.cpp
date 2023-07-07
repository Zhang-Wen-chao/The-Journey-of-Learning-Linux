// 637. Average of Levels in Binary Tree
// https://leetcode.com/problems/average-of-levels-in-binary-tree/

#include "../../BinaryTreeUtils.hpp"

std::vector<double> averageOfLevels(TreeNode<int>* root) {
    std::vector<double> result;
    if (root == nullptr) return result;

    std::queue<TreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        double sum = 0.0;
        for (int i = 0; i < size; i++) {
            TreeNode<int>* curr = q.front();
            q.pop();

            sum += curr->val;

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        result.push_back(sum / size);
    }
    return result;
}

int main() {
    std::vector<int> levelOrderValues = {3, 9, 20, -1, -1, 15, 7};
    TreeNode<int>* root = buildTree(levelOrderValues, -1);

    std::vector<double> result = averageOfLevels(root);

    std::cout << "Average of Levels in Binary Tree:" << std::endl;
    printArray(result);

    return 0;
}