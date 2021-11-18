#include <iostream>
#include <string>
#include <stack>

//Vinayak

using namespace std;

class node {    //single node of the expression tree
public:
  char value;   //data stored in node
  node* left;   //leftChild
  node* right;  //rightChid
  node* next = NULL;  //next node for stack implementation

  node(char c) {
    this->value = c;   //intialize the with given value
    left = NULL;
    right = NULL;
  }

  node()   //intialize the without value
  {
    left = NULL;
    right = NULL;
  }

  friend class Stack;
  friend class expression_tree;
};

class Stack { 
  node* head = NULL;  //head of stack node

public:
  void push(node*);   //function delaration for push
  node* pop();        //function delaration for pop
  friend class expression_tree;
};

class expression_tree {
public:
  void inorder(node* x)
  {
    if (x == NULL)
      return;
    else {
      inorder(x->left);
      cout << x->value << "  ";
      inorder(x->right);
    }
  }

  void printPreorder(struct node* root)
  {
    if (root == NULL)
      return;

    /* first print data of node */
    cout << root->value << " ";

    /* then recur on left subtree */
    printPreorder(root->left);

    /* now recur on right subtree */
    printPreorder(root->right);
  }

  void printPostorder(struct node* root)
  {
    if (root == NULL)
      return;

    // first recur on left subtree
    printPostorder(root->left);

    // then recur on right subtree
    printPostorder(root->right);

    // now deal with the node
    cout << root->value << " ";
  }
};

void Stack::push(node* x)
{
  if (head == NULL) {
    head = x;
  }
  // We are inserting here nodes at the top of the stack [following LIFO principle]
  else {
    x->next = head;
    head = x;
  }
}

node* Stack::pop()
{
  // Poping out the top most[ pointed with head] element
  node* p = head;
  head = head->next;
  return p;
}

bool isOperator(char x)
{
  switch (x) {
  case '+':
  case '-':
  case '/':
  case '*':
    return true;
  }
  return false;
}

// Convert prefix to Postfix expression
string preToPost(string pre_exp)
{

  stack<string> s;
  // length of expression
  int length = pre_exp.size();

  // reading from right to left
  for (int i = length - 1; i >= 0; i--)
  {
    // check if symbol is operator
    if (isOperator(pre_exp[i]))
    {
      // pop two operands from stack
      string op1 = s.top();
      s.pop();
      string op2 = s.top();
      s.pop();

      // concat the operands and operator
      string temp = op1 + op2 + pre_exp[i];

      // Push string temp back to stack
      s.push(temp);
    }

    // if symbol is an operand
    else {

      // push the operand to the stack
      s.push(string(1, pre_exp[i]));
    }
  }

  // stack contains only the Postfix expression
  return s.top();
}

int main()
{
  
  int choise;
  Stack e;
  expression_tree a;
  node* x, * y;
  node* z = new node();

  for (size_t i = 0; i < 100; i++)
  {
  cout << "Menu: \n \t 1.Postfix Expretion Tree \n \t 2.Prefix Expression Tree \n \t 3. Inoder Traversal" <<
    "\n \t 4. Postorder Traversal \n \t 5. Preorder Traversal";
  cin >> choise;  

  if (choise == 1) {
    string s;
    cout << "Enter POSTORDER expression to construct tree for:";
    cin >> s;

    int l = s.length();
    for (int i = 0; i < l; i++) {
      // if read character is operator then poping two
      // other elements from stack and making a binary
      // tree
      if (s[i] == '+' || s[i] == '-' || s[i] == '*'
        || s[i] == '/' || s[i] == '^') {
        z = new node(s[i]);
        x = e.pop();
        y = e.pop();
        z->left = y;
        z->right = x;
        e.push(z);
      }
      else {
        z = new node(s[i]);
        e.push(z);
      }
    }
  }
  else if (choise == 2) {
    string s;
    cout << "Enter PREFIX expression to construct tree for:";
    cin >> s;
    s = preToPost(s);

    int l = s.length();
    for (int i = 0; i < l; i++) {
      // if read character is operator then poping two
      // other elements from stack and making a binary
      // tree
      if (s[i] == '+' || s[i] == '-' || s[i] == '*'
        || s[i] == '/' || s[i] == '^') {
        z = new node(s[i]);
        x = e.pop();
        y = e.pop();
        z->left = y;
        z->right = x;
        e.push(z);
      }
      else {
        z = new node(s[i]);
        e.push(z);
      }
    }
  }
  else if (choise == 3) {
    cout << " The Inorder Traversal of Expression Tree: ";
    a.inorder(z);
  }
  else if (choise == 4)
  {
    cout << " The Preorder Traversal of Expression Tree: ";
    a.printPreorder(z);
  }
  else if (choise == 5)
  {
    cout << " The Postorder Traversal of Expression Tree: ";
    a.printPostorder(z);
  }
}
  return 0;
};
