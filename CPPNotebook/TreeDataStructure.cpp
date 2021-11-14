#include<iostream>

using namespace std;

class node
{
public:
  char data;
  node* leftChild;
  node* rightChild;
};

class Lstack
{
private:

  struct stacknode {
    node data;
    struct stacknode* next;
  };
    

public:

  stacknode* top;

  Lstack() {
    top = NULL;
  }

  ~Lstack()
  {
    stacknode* temp;
    temp = top;
    if (temp == NULL)
      delete temp;
    else {
      while (temp != NULL) {
        temp = temp->next;
        top = NULL;
        top = temp;
      }
      delete temp;
    }
  }

  void Push(node item) {
    stacknode* myStacknode;
    myStacknode = new stacknode;
    myStacknode->next = NULL;
    myStacknode->data = item;
    myStacknode->next = mystack.top;
    mystack.top = myStacknode;
  }

  int sempty(stacknode* temp) {
    if (temp == NULL)
      return 1;
    else
      return 0;
  }

  node* pop() {
    node item;
    stacknode temp;
    item = mystack.top->data;
    temp = *mystack.top;
    *mystack.top = *mystack.top->next;
    delete &temp;
    return(&item);
  }

  int display() {
    stacknode* temp;
    temp = mystack.top;
    if (sempty(temp))
      cout << "The stack empty";
    else {
      while (temp != NULL)
      {
        cout << " " << temp->data.data;
        temp = temp->next;
      }
    }
  }

  void create(node mynode) {
     Push(mynode);
  }

  void show() {
    display();
  }
} mystack;




//class Tree
//{
//public:
//  node* root;
//
//  Tree()
//  {
//    root = NULL;
//  }
//
//  node* BUILDTREE() {
//
//    cout << "Enter the postfix expression:";
//    char expression[200];
//
//    cin >> expression;
//
//    node* root = new node;
//
//    for (int i = 0; expression[i] != '\0'; i++) {
//      if (expression != "+" or "-" or "*" or "/") {
//        node* temp = new node;
//        temp->data = expression[i];
//        temp->leftChild = temp->rightChild = NULL;
//        mystack.Push(temp);
//
//      }
//      else //operator
//
//      {
//        root->data = expression[i];
//        root->rightChild = NULL;
//        root->leftChild = NULL;
//        root->rightChild = mystack.pop();
//        root->leftChild = mystack.pop();
//        mystack.Push(root);
//      }
//
//      root = mystack.pop();
//      return root;
//    };
//    ////////////////////////////////////////////////////////////////////////////////////////
//
//  };
//
//  
//};

  int main() {

    node mynode;
    mynode.data = 'd';

    mystack.display();
    mystack.Push(mynode);
    mystack.display();
    cout << mystack.pop()->data;
    mystack.display();


    return 0;

  }
