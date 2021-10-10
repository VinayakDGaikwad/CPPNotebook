#include<iostream>

using namespace std;

class linkedlist {
private:
  struct node {
    int data;
    struct node* next;
  };

  struct node* head = new node;

public:
  linkedlist() {
    head = NULL;
  }

  void display() {
    struct node* temp = head;

    if (temp == NULL) {
      cout << "No List";
      return;
    }


    cout << "List: ";
    while (temp->next != nullptr) {
      cout << " --->" << temp->data;
      temp = temp->next;
    }

    cout << " :END";
  }

  void get_data() {
    cout << "How many nodes do you want?";
    int n;
    int i = 0;
    int data;
    cin >> n;

    node* temp = new node;
    head = temp;


    while (i < n) {
      cin >> data;
      temp->data = data;
      temp->next = new node;

      temp = temp->next;

      i++;
    }

    temp->next = NULL;

  };

  void append_last(int data) {
    struct node* temp = head;
    struct node* new_node = new node;
    new_node->data = data;
    new_node->next = NULL;

    if (head != NULL) {
      while (temp->next != NULL) {
        temp = temp->next;
      }

      temp->next = new_node;
    }
    else {
      head = new_node;
    }

  };

};

