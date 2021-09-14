#include<iostream>

using namespace std;

class linkedlist {
private:
	struct node {
		int data;
		struct node* next;
	};

	struct node* head;

public:
	linkedlist() {
		head = NULL;
	}

	void display() {
		struct node* temp = head;

		while (temp != NULL) {
			cout << "    " << temp->data;
			temp = temp->next;
		}
	}

	void append_last(int data){
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

int main() {

	linkedlist L1;
	L1.append_last(23);
	L1.append_last(22);
	L1.append_last(24);
	L1.append_last(2555);
	L1.display();
	return 0;

}