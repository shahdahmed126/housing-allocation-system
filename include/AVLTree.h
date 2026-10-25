#ifndef AVLTREE_H
#define AVLTREE_H

#include "Applicant.h"

// A single node in the AVL tree.
// Stores one Applicant and links to its left and right children.
struct AVLNode {
  Applicant data;  // the applicant stored in this node
  AVLNode *left;   // pointer to left child  (lower  ID)
  AVLNode *right;  // pointer to right child (higher ID)
  int height;      // height of this node, used for balancing

  // Constructor — initialises a new leaf node with no children
  AVLNode(Applicant applicant)
      : data(applicant), left(nullptr), right(nullptr), height(1) {}
};

// AVL Tree that stores Applicant objects ordered by applicant ID.
// Self-balancing: keeps search, insert at O(log n).
class AVLTree {
public:
  // Constructor — starts with an empty tree
  AVLTree();

  // Insert a new applicant into the tree
  void insert(Applicant applicant);

  // Search for an applicant by ID.
  // Returns a pointer to the Applicant if found, nullptr if not.
  Applicant *searchByID(int id);

  // Print all applicants in ascending order of ID (left → root → right)
  void inOrderTraversal();

private:
  AVLNode *root; // pointer to the root of the tree

  // --- Rotation helpers (fix imbalance after insert) ---
  AVLNode *rotateLeft(AVLNode *node);
  AVLNode *rotateRight(AVLNode *node);

  // --- Height & balance helpers ---
  int getHeight(AVLNode *node);  // returns 0 if node is nullptr
  int getBalance(AVLNode *node); // returns height(left) - height(right)

  // --- Recursive helpers (do the real work) ---
  AVLNode *insertHelper(AVLNode *node, Applicant applicant);
  Applicant *searchHelper(AVLNode *node, int id);
  void inOrderHelper(AVLNode *node);
};

#endif // AVLTREE_H
