#pragma once

#include <iostream>
#include <queue>
#include <string>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

void printTree(const TreeNode *root) {
  std::string val = (root == nullptr) ? "null" : std::to_string(root->val);
  std::cout << " " << val << ",";
  if (root != nullptr) {
    printTree(root->left);
    printTree(root->right);
  }
}

TreeNode *createTree(const std::vector<int> &input) {
  if (input.size() == 0 || input[1] == INT_MIN) {
    return nullptr;
  }

  auto *root = new TreeNode(input[0]);
  std::queue<TreeNode *> nodeQueue;
  nodeQueue.push(root);

  size_t i = 1;
  while (i < input.size()) {
    auto *currentNode = nodeQueue.front();
    nodeQueue.pop();
    if (input[i] != INT_MIN) {
      currentNode->left = new TreeNode(input[i]);
      nodeQueue.push(currentNode->left);
    }
    ++i;
    if ((i < input.size()) && (input[i] != INT_MIN)) {
      currentNode->right = new TreeNode(input[i]);
      nodeQueue.push(currentNode->right);
    }
    ++i;
  }

  return root;
}