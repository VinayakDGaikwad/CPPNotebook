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
    else
    {
      int x = queue[front];
      front = (front + 1) % MAX;
      return x;
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

  int main()
  {
    clrqueue c;
    c.Enqueue(1);
    c.Enqueue(2);
    c.Enqueue(3);
    c.Dequeue();
    c.display();

    return 0;
  }
