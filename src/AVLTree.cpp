#include "AVLTree.h"
#include <iostream>
using namespace std;

// ============================================================
// Constructor
// ============================================================

AVLTree::AVLTree() {
  root = nullptr;
}

// ============================================================
// Height & Balance helpers
// ============================================================

// Returns the height of a node.
// Returns 0 if the node is nullptr (empty subtree).
int AVLTree::getHeight(AVLNode *node) {
  if (node == nullptr) {
    return 0;
  }
  return node->height;
}

// Returns the balance factor of a node.
// balance = height(left subtree) - height(right subtree)
//   > 1  → left-heavy  → need right rotation
//   < -1 → right-heavy → need left rotation
int AVLTree::getBalance(AVLNode *node) {
  if (node == nullptr) {
    return 0;
  }
  return getHeight(node->left) - getHeight(node->right);
}

// ============================================================
// Rotations
// ============================================================

// Left Rotation — used when the right subtree is too tall.
//
//     node                 rightChild
//    /    \               /          \
//   T1   rightChild  →  node         T3
//        /      \       /   \
//       T2      T3     T1   T2
//
AVLNode *AVLTree::rotateLeft(AVLNode *node) {
  AVLNode *rightChild = node->right;
  AVLNode *T2 = rightChild->left;

  // Perform rotation
  rightChild->left = node;
  node->right = T2;

  // Update heights (node first, then rightChild — order matters)
  node->height = 1 + max(getHeight(node->left), getHeight(node->right));
  rightChild->height = 1 + max(getHeight(rightChild->left), getHeight(rightChild->right));

  return rightChild; // new root of this subtree
}

// Right Rotation — used when the left subtree is too tall.
//
//       node             leftChild
//      /    \           /         \
// leftChild  T3  →    T1          node
//  /      \                      /    \
// T1      T2                    T2    T3
//
AVLNode *AVLTree::rotateRight(AVLNode *node) {
  AVLNode *leftChild = node->left;
  AVLNode *T2 = leftChild->right;

  // Perform rotation
  leftChild->right = node;
  node->left = T2;

  // Update heights
  node->height = 1 + max(getHeight(node->left), getHeight(node->right));
  leftChild->height = 1 + max(getHeight(leftChild->left), getHeight(leftChild->right));

  return leftChild; // new root of this subtree
}

// ============================================================
// Insert
// ============================================================

// Public wrapper — kicks off the recursive insert
void AVLTree::insert(Applicant applicant) {
  root = insertHelper(root, applicant);
}

// Recursive insert — ordered by applicant ID.
// After placing the node, updates height and checks balance.
AVLNode *AVLTree::insertHelper(AVLNode *node, Applicant applicant) {

  // --- Step 1: Normal BST insert ---
  if (node == nullptr) {
    return new AVLNode(applicant); // base case: place node here
  }

  if (applicant.getId() < node->data.getId()) {
    node->left = insertHelper(node->left, applicant);
  } else if (applicant.getId() > node->data.getId()) {
    node->right = insertHelper(node->right, applicant);
  } else {
    // Duplicate IDs are not allowed — return unchanged
    return node;
  }

  // --- Step 2: Update height of current node ---
  node->height = 1 + max(getHeight(node->left), getHeight(node->right));

  // --- Step 3: Check balance factor ---
  int balance = getBalance(node);

  // --- Step 4: Fix imbalance with rotations ---

  // Case 1: Left-Left (right rotation fixes it)
  //   Inserted into the left child's LEFT subtree
  if (balance > 1 && applicant.getId() < node->left->data.getId()) {
    return rotateRight(node);
  }

  // Case 2: Right-Right (left rotation fixes it)
  //   Inserted into the right child's RIGHT subtree
  if (balance < -1 && applicant.getId() > node->right->data.getId()) {
    return rotateLeft(node);
  }

  // Case 3: Left-Right (left rotation on child, then right rotation on node)
  //   Inserted into the left child's RIGHT subtree
  if (balance > 1 && applicant.getId() > node->left->data.getId()) {
    node->left = rotateLeft(node->left);
    return rotateRight(node);
  }

  // Case 4: Right-Left (right rotation on child, then left rotation on node)
  //   Inserted into the right child's LEFT subtree
  if (balance < -1 && applicant.getId() < node->right->data.getId()) {
    node->right = rotateRight(node->right);
    return rotateLeft(node);
  }

  // Tree is still balanced — return unchanged node
  return node;
}

// ============================================================
// Search
// ============================================================

// Public wrapper for search
Applicant *AVLTree::searchByID(int id) {
  return searchHelper(root, id);
}

// Full tree traversal search by applicant ID.
// The tree is ordered by priorityScore, NOT by ID.
// This means we cannot use BST binary search for ID lookups —
// we must visit every node until we find a match.
Applicant *AVLTree::searchHelper(AVLNode *node, int id) {
  if (node == nullptr) {
    return nullptr; // base case: nothing here
  }

  // Check current node
  if (node->data.getId() == id) {
    return &node->data; // found
  }

  // Search left subtree first
  Applicant *found = searchHelper(node->left, id);
  if (found != nullptr) {
    return found; // found in left subtree
  }

  // If not in left, search right subtree
  return searchHelper(node->right, id);
}

// ============================================================
// In-Order Traversal (prints sorted by ID)
// ============================================================

// Public wrapper
void AVLTree::inOrderTraversal() {
  if (root == nullptr) {
    cout << "Tree is empty." << endl;
    return;
  }
  inOrderHelper(root);
}

// Recursive in-order: left → current → right
void AVLTree::inOrderHelper(AVLNode *node) {
  if (node == nullptr) {
    return;
  }
  inOrderHelper(node->left);
  // cout << "DEBUG traversal: " << node->data.getName() << endl;
  node->data.display();
  inOrderHelper(node->right);
}
