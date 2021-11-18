// Vinayak Gaikwad

#include<iostream>
#include<stdio.h>

#define MAX 5

using namespace std;

class clrqueue
{
  int queue[MAX];
  int front;
  int rear;

public:
   clrqueue() {
    front = -1;
    rear = -1;
  }

  void Enqueue(int n)
  {
    if (isEmpty())
    {
      front = rear = 0;
    }
    else if (isFull()) {
      return;
    }
    else {
      rear = (rear + 1) % MAX;
    }

    queue[rear] = n;
  }

  int Dequeue()
  {
    if (isEmpty()){
      return 0;
    }
    else if (front == rear) {
      front = -1;
      rear = -1;
      return 0;
    }
    else {
      int re = queue[front];
      front = (front + 1) % MAX;
      return re;

    }
  }

  bool isEmpty() {
    if (front == -1 && rear == -1) {
      return true;
    }
    else {
      return false;
    }
  }

  bool isFull() {
    if (front == (rear + 1) % MAX) {
      return true;
    }
    else {
      return false;
    }
  }

  void display()
  {
    int i = front;
    while (i != rear)
    {
      cout << " --- " << queue[i];
      i = (i + 1) % MAX;
    }

    cout << " --- " << queue[i];
  }
};

  //int main()
  //{
  //  clrqueue c;
  //  int input;
  //  for (size_t i = 0; i < 100; i++)
  //  {
  //    cout << "Menu: \n \t 1. Insert (Inqueue) \n\t 2. Remove (Dequeue) \n\t 3. Display";
  //    cin >> input;
  //    int data;
  //    switch (input)
  //    {
  //    case 1:
  //      cin >> data;
  //        c.Enqueue(data);
  //      break;
  //    case 2:
  //      c.Dequeue();
  //      break;
  //    case 3:
  //      c.display();
  //      break;
  //    }
  //    }
  //  
  //  return 0;
  //}
