#include<iostream>
#include<stdlib.h>

using namespace std;

class Lstack
{
private:

  typedef struct stack {
    int data;
    struct stack* next;
  } node;
  node *top;


public:
  Lstack() {
    top = NULL;
  }

  ~Lstack()
  {
    node* temp;
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

  void Push(int item, node** top) {
    node* mynode;
    mynode = new node;
    mynode->next = NULL;
    mynode->data = item;
    mynode->next = *top;
    *top = mynode;
  }

  int sempty(node* temp) {
    if (temp == NULL)
      return 1;
    else
      return 0;
  }

  int pop(node** top) {
    int item;
    node* temp;
    item = (*top)->data;
    temp = *top;
    *top = (*top)->next;
    delete temp;
    return(item);
  }

  int display(node* head) {
    node* temp;
    temp = head;
    if (sempty(temp))
      cout << "The stack empty";
    else {
      while (temp != NULL)
      {
        cout << " " << temp ->data;
        temp = temp->next;
      }
    }
  }

  void create() {
    int data;
    cout << "Enter the data:";
    cin >> data;
    Push(data, &top);
  }

  void remove() {
    int item;
    if (sempty(top)) {
      cout << "Stack underflow";
    }
    else {
    item = pop(&top);
    cout << "The opped node is" << item;
    }
  }

  void show() {
    display(top);
  }
};
