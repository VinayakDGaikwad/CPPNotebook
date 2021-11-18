// Insertion in Threaded Binary Search Tree.
#include<stdio.h>
#include <iostream>
using namespace std;

struct Node
{
  struct Node* left, * right;
  int info;

  // False if left pointer points to predecessor
  // in Inorder Traversal
  bool lthread;

  // False if right pointer points to successor
  // in Inorder Traversal
  bool rthread;
};

// Insert a Node in Binary Threaded Tree
struct Node* insert(struct Node* root, int ikey)
{
  // Searching for a Node with given value
  Node* ptr = root;
  Node* par = NULL; // Parent of key to be inserted
  while (ptr != NULL)
  {
    // If key already exists, return
    if (ikey == (ptr->info))
    {
      printf("Duplicate Key !\n");
      return root;
    }

    par = ptr; // Update parent pointer

    // Moving on left subtree.
    if (ikey < ptr->info)
    {
      if (ptr->lthread == false)
        ptr = ptr->left;
      else
        break;
    }

    // Moving on right subtree.
    else
    {
      if (ptr->rthread == false)
        ptr = ptr->right;
      else
        break;
    }
  }

  // Create a new node
  Node* tmp = new Node;
  tmp->info = ikey;
  tmp->lthread = true;
  tmp->rthread = true;

  if (par == NULL)
  {
    root = tmp;
    tmp->left = NULL;
    tmp->right = NULL;
  }
  else if (ikey < (par->info))
  {
    tmp->left = par->left;
    tmp->right = par;
    par->lthread = false;
    par->left = tmp;
  }
  else
  {
    tmp->left = par;
    tmp->right = par->right;
    par->rthread = false;
    par->right = tmp;
  }

  return root;
}

// Returns inorder successor using rthread
struct Node* inorderSuccessor(struct Node* ptr)
{
  // If rthread is set, we can quickly find
  if (ptr->rthread == true)
    return ptr->right;

  // Else return leftmost child of right subtree
  ptr = ptr->right;
  while (ptr->lthread == false)
    ptr = ptr->left;
  return ptr;
}

void preorder(struct Node* node)
{
  if (node == NULL)
    return;

  /* first print data of node */
  cout << node->info << " ";

  /* then recur on left subtree */
  if (node->lthread == false)
  preorder(node->left);

  /* now recur on right subtree */
  if(node->rthread == false)
  preorder(node->right);
}

// Printing the threaded tree
void inorder(struct Node* root)
{
  if (root == NULL)
    printf("Tree is empty");

  cout << "Inorder traversal of the threaded binary tree is: ";

  // Reach leftmost node
  struct Node* ptr = root;
  while (ptr->lthread == false)
    ptr = ptr->left;

  // One by one print successors
  while (ptr != NULL)
  {
    printf("%d ", ptr->info);
    ptr = inorderSuccessor(ptr);
  }
}

// Driver Program
int main()
{
  struct Node* root = NULL;

  for (;;) {
        cout << "\nMenu: \n \t 1. Insert Node \n \t 2.Inorder \n \t 3. Preorder";
        int input;
        cin >> input;
        int data;
        switch (input)
        {
        case 1:
          cout << "Enter thr node data to be inserted:";
          cin >> data;
          root = insert(root, data);
          break;
        case 2:
          inorder(root);
          break;
        case 3:
          cout << "\n Preorder traversal of the threaded binary tree is: ";
          preorder(root);
          break;
        }    
      }
  return 0;
}
