#include<iostream>

using namespace std;

struct node {
	int data;
    node* next;
};

int LinkedListSource() {
	node* head=nullptr;   //pointer to node "head"
	node* node1 = nullptr;
	node* node2=nullptr;
	node* node3=nullptr;

	node* temp = nullptr;

	head->data = 4234234;
	head->next = node2;

	node1->data = 3242424;
	node1->next = node2;

	node2->data = 243234;
	node2->next = node3;

	node3->data = 243432;
	node3->next = NULL;
	
	int location;
	cout << "INSERT AFTER WHAT?:";
	cin >> location;

	//while (temp->next != NULL) {
		//if (data = )


	//}
	return 0; 
		//write code for insert before and insert after
}