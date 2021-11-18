#include<conio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

int flage = 0;

//function to find height of tree
int max(int value1, int value2) {
  return ((value1 > value2) ? value1 : value2);
}

//a single binary tree node
struct BSTnode {
  
public:
  int data;
  BSTnode* left, * right;

  //intialize the node
  BSTnode(int x) {
    data = x;
    left = right = NULL;
  }
};

struct BSTnode* minValueNode(struct BSTnode* node)
{
  struct BSTnode* current = node;

  /* loop down to find the leftmost leaf */
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

//functions for bianary search tree
class BST {
public:
  BSTnode* root;

  //constructor
  BST() {
    root = NULL;
  }

  //create a new tree or insert in the existing tree
  BSTnode* insert(BSTnode * root, int DATA) {
    //if the node does not have any children
    if (root == NULL) {
      root = new BSTnode(0);
      root->data = DATA;
      root->left = NULL;
      root->right = NULL;
    }

    //if the node has value greater than the current node then
    if (DATA > root->data) {
      //insert new node as right child
        root->right = insert(root->right, DATA);
    }

    //if the node has value smaller than the last node then
    if (DATA < root->data) {
      //insert new node as left child
         root->left = insert(root->left, DATA);
    }
    //return for the cases
    return root;
  };

  //to delete the node
  struct BSTnode* delet(struct BSTnode* T, int key)
  {
    // base case
    if (T == NULL)
      return T;

    // If the key to be deleted is
    // smaller than the root's
    // key, then it lies in left subtree
    if (key < root->data)
      T->left = delet(T->left, key);

    // If the key to be deleted is
    // greater than the root's
    // key, then it lies in right subtree
    else if (key > root->data)
      T->right = delet(T->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else {
      // node has no child
      if (T->left == NULL and T->right == NULL)
        return NULL;

      // node with only one child or no child
      else if (T->left == NULL) {
        struct BSTnode* temp = T->right;
        free(root);
        return temp;
      }
      else if (T->right == NULL) {
        struct BSTnode* temp = T->left;
        free(root);
        return temp;
      }

      // node with two children: Get the inorder successor
      // (smallest in the right subtree)
      struct BSTnode* temp = minValueNode(root->right);

      // Copy the inorder successor's content to this node
      root->data = temp->data;

      // Delete the inorder successor
      root->right = delet(root->right, temp->data);
    }
    return root;
  }

  //inorder display of the binary search tree
  void inoder_traversal(BSTnode* T) {
    if (T != NULL) {
      //traverse the left subtree
      inoder_traversal(T->left);

      //print the root node
      cout << " " << T->data;

      //traverse the right subtree
      inoder_traversal(T->right);
    }
  };

  //to perform binary search, returns pointer to the node
  BSTnode* search(int x) {
    BSTnode* T = root;

    //untill the leaf node is reached
    while (T != NULL) {
      if (T != NULL)
        //node found so return the pointer
        return T;
      if (x > root->data)
        T = T->right;
      else
        T = T->left;
    }

    //if node found then return nothing 
    return NULL;
  };

  //to measure the height of the tree
  int height(BSTnode* T) {
    if (T == NULL)
      return -1;
    else
    {
      // compute the depth of each subtree
      int lDepth = height(T->left);
      int rDepth = height(T->right);

      //use the larger one
      if (lDepth > rDepth)
        return(lDepth + 1);
      else return(rDepth + 1);
    }
  }

  //traverse inorder 
  void display_leaf_nodes(BSTnode* T) {
    if (T != NULL) {
      //traverse the left subtree
      inoder_traversal(T->left);

      //print the root node
      if (T->left == NULL and T->right == NULL) {
        cout << " Leaf: " << T->data;
      }

      //traverse the right subtree
      inoder_traversal(T->right);
    }
  };
};

int main() {
  BST myTree;
  for (size_t i = 0; i < 100; i++)
  {
    int input;
    cout << "\n \t Menu: \n \t 1.Insert \n \t 2. Delete \n \t 3. Search \n \t 4. Display (Inorder) \n \t 5.Depth of tree \n\t 6.Display all leaf nodes.";
    cin >> input;
    switch (input)
    {
    case 1:
      cout << "Enter number to insert:";
      cin >> input;
      myTree.root = myTree.insert(myTree.root, input);
      break;
    case 2:
      cout << "Enter sub tree to delete: ";
      cin >> input;
      myTree.delet(myTree.root, input);
      break;
    case 3:
      cout << "Enter node to search: ";
      cin >> input;
      if (myTree.search(input) == NULL) {
        cout << "NOT FOUND!";
      }
      else {
        cout << myTree.search(input)->data;
      }
      break;
    case 4:
      myTree.inoder_traversal(myTree.root);
      break;
    case 5:
      cout << "Deapth of tree is:" << myTree.height(myTree.root);
      break;
    case 6:
      cout << "All leaf nodes:";
      myTree.display_leaf_nodes(myTree.root);
    }
  }

  return 0;
};
