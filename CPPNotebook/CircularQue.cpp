//#include<iostream>
//#include<math.h>
//
//using namespace std;
//
//class queue
//{
//  int QUE[10];
//  int front, rear;
//
//public:
//
//  queue() {
//    front = -1;
//    rear = 0;
//  }
//
//  void init() {
//    int i = 0;
//    for (i = 0; i < 10; i++)
//      QUE[i] = 0;
//  }
//
//  void insert(int item) {
//    if (abs((front - rear) < 10))
//    {
//      cout<<"QUEUE is full";
//      return;
//    }
//
//    if (front == (rear + 1) % 10) {
//      front = rear = 0;
//    }
//    else {
//      rear = (rear + 1) % 10;
//      QUE[rear] = item;
//    }   
//
//  }
//
//  int delete_from_queue() {
//    int val;
//    if (front == -1) {
//      cout << "Queue is already empty";
//      return 0;
//    }
//
//    val = QUE[front];
//    if (front == rear) {
//      front = rear = -1;
//    }
//    else {
//      front = (front + 1 % 10);
//    }
//
//    return val;
//  }
//
//  void display() {
//    int i;
//    i = front;
//    while (i != rear)
//    {
//      cout << QUE[i] << " ";
//      i = (i + 1) % 10;
//    }
//    cout << QUE[i] << endl;
//  }
//}
