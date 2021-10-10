//#include<iostream>
//#include<conio.h>
//#include<stdlib.h>
//
//using namespace std;
//
//template<class Type>
//class Stack
//{
//	Type s[10];
//	int top, n;
//public:
//	Stack()
//	{
//		top = -1;
//		cout << "\n\t Enter the Stack Size : ";
//		cin >> n;
//	}
//	void push(Type elt)
//	{
//		if (top < n - 1)
//			s[++top] = elt;
//		else
//			cout << "\n\t stack is full. Can't insert " << elt << endl;
//	}
//	void pop()
//	{
//		if (top < 0)
//			cout << "\n\t stack is empty.\n";
//		else
//			cout << "\n\t Poped elt : " << s[top--];
//	}
//	void stk_operation();
//};
//
//template<class Type>
//void Stack<Type> ::stk_operation()
//{
//	int choice = 1, i;
//	Type elt;
//	while (choice > 0 && choice < 3)
//	{
//		cout << "\n\n\t1.PUSH\t2.POP\tAny Key To Exit\n\tChoice : ";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1: //push
//			cout << "\n\tEnter the Elt to push : ";
//			cin >> elt;
//			push(elt);
//			cout << "\n\t\tstack content :\n\n\t";
//			for (i = 0; i <= top; i++)
//				cout << s[i] << "\t";
//			break;
//		case 2: //pop
//			pop();
//			cout << "\n\t\tstack content :\n\n\t";
//			for (i = 0; i <= top; i++)
//				cout << s[i] << "\t";
//			break;
//		}
//	}
//}
//void main()
//{
//	
//	cout << "\n\ INT";
//	Stack<int> stk1;
//	cout << "\n FLOAT\n";
//	Stack<float> stk2;
//	int ch;
//	while (1)
//	{
//		cout << "\n\STACK OPERATION \n\n";
//		cout << "1.INT STACK\t2.FLOAT STK\tAny Key To Exit\n\tChoice : ";
//		cin >> ch;
//		switch (ch)
//		{
//		case 1: //perform stk operation on int stk
//			stk1.stk_operation();
//			break;
//		case 2: //float
//			stk2.stk_operation();
//			break;
//		default: exit(0);
//		}
//	}
//}